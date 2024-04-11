#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
const int N=200005;
int T,n,m,x[N],p[N],id[N],ans[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(m);
		map<int,LL>k,b;
		rep(i,1,n){
			rd(x[i]),rd(p[i]);
			int l=x[i]-p[i];
			int r=x[i]+p[i];
			k[l]+=1;
			b[l]-=l;
			
			k[x[i]]-=1;
			b[x[i]]+=l;
			
			k[x[i]]-=1;
			b[x[i]]+=r;
			
			k[r]+=1;
			b[r]-=r;
			
			id[i]=i;
		}
		LL kk=0,bb=0;
		vector<pair<int,LL> >pts;
		multiset<LL>S1,S2;
		// S1: p[i]+x[i]>=
		// S2: p[i]-x[i]>=
		for(auto i=k.begin(),j=b.begin();i!=k.end()&&j!=b.end();++i,++j){
			kk+=i->second;
			bb+=j->second;
			i->second=kk;
			j->second=bb;
			LL y=1LL*kk*i->first+bb;
			if(y>m){
				pts.eb(i->first,y-m);
				S2.insert(i->first+y-m);
			}
		}
		
		sort(id+1,id+n+1,[&](int lhs,int rhs){return x[lhs]<x[rhs];});
		int pos=0;
		rep(_,1,n){
			int i=id[_];
			while(pos<SZ(pts)&&pts[pos].first<x[i]){
				S2.erase(S2.find(pts[pos].first+pts[pos].second));
				S1.insert(-pts[pos].first+pts[pos].second);
				++pos;
			}
			if((S2.empty()||p[i]>=*--S2.end()-x[i])&&(S1.empty()||p[i]>=*--S1.end()+x[i])){
				ans[i]=1;
			}else{
				ans[i]=0;
			}
		}
		rep(i,1,n)putchar(ans[i]+48);
		putchar('\n');
	}
	
	return 0;
}