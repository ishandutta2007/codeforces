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
int n,m,q,k;
int a[MN],b[MN],f[MN],g[MN];
char s[MN][6];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d%s",a+i,s[i]+1);
	F(i,1,n){for(int j=1;s[i][j];++j)b[i]|=1<<(s[i][j]-'A');}
	int ans=inf;
	F(i,1,n)if(b[i]==7)ans=min(ans,a[i]);
	F(j,1,n-1)F(k,j+1,n)if((b[j]|b[k])==7)ans=min(ans,a[j]+a[k]);
	F(i,1,n-2)F(j,i+1,n-1)F(k,j+1,n)if((b[i]|b[j]|b[k])==7)ans=min(ans,a[i]+a[j]+a[k]);
	printf("%d\n",ans==inf?-1:ans);
	return 0;
}