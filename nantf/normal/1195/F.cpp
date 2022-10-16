#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=300030;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
struct ques{
	int l,r,id;
	bool operator<(const ques &q)const{return r<q.r;}
}q[maxn];
struct seg{
	int x,y,d;
	bool operator<(const seg &s)const{
		if(x!=s.x) return x<s.x;
		if(y!=s.y) return y<s.y;
		return d<s.d;
	}
};
int n,Q,ans[maxn],tmpx[maxn],tmpy[maxn],bit[maxn];
vector<seg> v[maxn];
map<seg,int> at;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void update(int p,int v){for(int i=p;i<=n;i+=i&-i) bit[i]+=v;}
int query(int p){int s=0;for(int i=p;i;i-=i&-i) s+=bit[i];return s;}
int query(int l,int r){return query(r)-query(l-1);}
int main(){
	n=read();
	FOR(i,1,n){
		int k=read();
		FOR(j,1,k) tmpx[j]=read(),tmpy[j]=read();
		FOR(j,1,k){
			int dx=tmpx[j]-tmpx[j==1?k:j-1],dy=tmpy[j]-tmpy[j==1?k:j-1],tp=0;
			if(dx<0 || dx==0 && dy<0) tp=1;
			int g=gcd(dx,dy);
			dx/=g;dy/=g;
			if(dx<0 || dx==0 && dy<0) dx=-dx,dy=-dy; 
			v[i].push_back((seg){dx,dy,tp});
		}
	}
	Q=read();
	FOR(i,1,Q){
		int l=read(),r=read();
		q[i]=(ques){l,r,i};
	}
	sort(q+1,q+Q+1);
	int cur=1;
	FOR(i,1,Q){
		while(cur<=q[i].r){
			FOR(j,0,(int)v[cur].size()-1){
				if(at[v[cur][j]]) update(at[v[cur][j]],-1);
				update(at[v[cur][j]]=cur,1);
			}
			cur++;
		}
		ans[q[i].id]=query(q[i].l,q[i].r);
	}
	FOR(i,1,Q) printf("%d\n",ans[i]);
}