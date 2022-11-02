#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define DB long double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
inline int read(){
	int nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define mod 1000000007
#define M 1200020
int n,m;
set<int>inq;
struct evt{
	LL tim; int id,typ; evt(){} evt(LL _tim,int _id,int _typ){tim=_tim,id=_id,typ=_typ;}
	bool operator < (const evt&ot)const{
		if(tim!=ot.tim) return tim>ot.tim;
		return typ>ot.typ;
	}
};
priority_queue<evt>Q;
priority_queue<int>st;
int p[M]; LL ans[M],now,las;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++) p[i]=read(),Q.push(evt(p[i],i,1));
	while(!Q.empty()||!st.empty()){
		if(!Q.empty()){
			evt tmp=Q.top(); Q.pop(); int x=tmp.id;
			if(tmp.typ<0) inq.erase(x),ans[x]=tmp.tim;
			else st.push(-x); now=tmp.tim;
			if(!Q.empty()&&Q.top().tim==now) continue;
		}
		if(!st.empty()){
			int x=-st.top(); st.pop();
			if(!inq.empty()){
				int y=(*(inq.begin()));
				if(y<x){st.push(-x);continue;}
			}
			inq.insert(x),ans[x]=max(now,las)+m;
			Q.push(evt(las=ans[x],x,-1));
		}
	}
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]); puts("");
	return 0;
}


/*

5 314
0 310 942 628 0

*/