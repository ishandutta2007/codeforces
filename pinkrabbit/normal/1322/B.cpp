#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 400005
#define MS (1<<12|7)
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,int e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n;
int a[MN],b[MS],ans;
int c[MS][MS];
vector<int>G[MS];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),++b[a[i]&0xfff];
	F(i,0,0xfff)F(j,i,0xfff)ans^=(i==j)?(b[i]%4>=2?(i+j)&0xfff:0):((b[i]&1)&&(b[j]&1)?(i+j)&0xfff:0);
	F(i,0,0xfff)b[i]=0;
	F(i,1,n)++b[a[i]>>12&0xfff],++c[a[i]>>12&0xfff][a[i]&0xfff],G[a[i]>>12&0xfff].pb(a[i]&0xfff);
	F(i,0,0xfff)F(j,1,0xfff)c[i][j]+=c[i][j-1];
	F(i,0,0xfff)sort(G[i].begin(),G[i].end());
	F(i,0,0xfff)F(j,i,0xfff){
		ll c0=0,c1=0;
		if(i==j){
			c0=(ll)b[i]*(b[i]-1)/2;
			int sz=G[i].size();
			F2(k,0,sz){
				int x=G[i][k];
				if(0xfff-x>=x)c1+=sz-c[i][0xfff-x];
				else c1+=sz-k-1;
			}
		}else{
			c0=(ll)b[i]*b[j];
			int sz1=G[i].size(),sz2=G[j].size();
			if(sz1<=sz2){
				for(int x:G[i])c1+=sz2-c[j][0xfff-x];
			}else{
				for(int x:G[j])c1+=sz1-c[i][0xfff-x];
			}
		}
		c0-=c1;
//		if(c0||c1)printf("%d,%d:%lld,%lld\n",i,j,c0,c1);
		ans^=((c0&1?i+j:0)^(c1&1?i+j+1:0))<<12;
	}
	printf("%d\n",ans);
	return 0;
}