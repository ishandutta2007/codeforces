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
#define mod 1000000007
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m,q,k,ans=1;
int a[MN],b[MN],f[MN],g[MN];
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
char s[MN];
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	F(i,1,n)if(s[i]=='m'||s[i]=='w')return puts("0"),0;
	a[0]=a[1]=1;
	F(i,2,n)a[i]=(a[i-2]+a[i-1])%mod;
	int cnt=0;
	F(i,1,n)if(s[i]=='u'||s[i]=='n'){if(i==n||s[i]!=s[i+1])++cnt,ans=(ll)ans*a[cnt]%mod,cnt=0;else++cnt;}else cnt=0;
	printf("%d\n",ans);
	return 0;
}