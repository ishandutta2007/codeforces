#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
inline char getc(){static char buf[1<<20],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getc()))f^=!(c^45);x=(c&15);while(isdigit(c=getc()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=1000005;
int T,n,m,a[N],b[N];
void gen(vector<long long>&res,vector<int>&v){
	sort(v.begin(),v.end());
	long long ss=0;
	each(x,v)ss+=x;
	res.resize(SZ(v)+1);
	rep(i,0,SZ(v)){
		res[i]=ss;
		if(i<SZ(v))ss-=v[i]*2;
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(m);
		rep(i,1,n)rd(a[i]);
		int g=0;
		rep(i,1,m){
			rd(b[i]);
			g=__gcd(g,b[i]);
		}
		vector<vector<int> >vec(g);
		vector<vector<long long> >key(g);
		rep(i,1,n)vec[i%g].pb(a[i]);
		rep(i,0,g-1){
			gen(key[i],vec[i]);
		}
		long long ans=-5e18;
		rep(i,0,1){
			long long cur=0;
			rep(j,0,g-1){
				long long tmp=-5e18;
				rep(k,0,SZ(key[j])-1)if((k&1)==(i&1)){
					tmp=max(tmp,key[j][k]);
				}
				if(tmp==-5e18)cur=-5e18;
				else cur+=tmp;
			}
			ans=max(ans,cur);
		}
		printf("%lld\n",ans);
	}
	return 0;
}