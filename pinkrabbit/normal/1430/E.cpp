#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,w[26];char s[MN];
int a[MN],b[MN],c[MN];
int bit[MN];
inline void add(int i){for(;i<=n;i+=i&-i)++bit[i];}
inline int qur(int i){int s=0;for(;i;i-=i&-i)s+=bit[i];return s;}
int main(){
	scanf("%d%s",&n,s+1);
	F(i,1,n)++w[s[i]-'a'];
	F(j,1,25)w[j]+=w[j-1];
	F(i,1,n)a[i]=w[s[i]-'a']--;
	reverse(s+1,s+n+1);
	F(j,0,25)w[j]=0;
	F(i,1,n)++w[s[i]-'a'];
	F(j,1,25)w[j]+=w[j-1];
	F(i,1,n)b[i]=w[s[i]-'a']--;
//	F(i,1,n)printf("%d%c",a[i]," \n"[i==n]);
//	F(i,1,n)printf("%d%c",b[i]," \n"[i==n]);
	F(i,1,n)c[a[i]]=i;
	F(i,1,n)a[i]=c[i];
	F(i,1,n)c[i]=a[b[i]];
//	F(i,1,n)printf("%d%c",c[i]," \n"[i==n]);
	ll ans=0;
	dF(i,n,1)ans+=qur(c[i]),add(c[i]);
	printf("%lld\n",ans);
	return 0;
}