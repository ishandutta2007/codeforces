#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define SZ(x) ((int)(x).size())
#define prts(x) return puts(x),0
#define pirtf(x) return printf("%d\n",x),0
#define re return
typedef long long LL;
typedef double ld;
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline LL Gcd(LL X,LL Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int B,LL E,int M){if(!(B%=M))return 0;int A=1;for(;E;E>>=1,B=(LL)B*B%M)E&1?A=(LL)A*B%M:0;return A;}
inline LL Pow(LL B,LL E,LL M){if(!(B%=M))return 0;LL A=1;for(;E;E>>=1,B=B*B%M)E&1?A=A*B%M:0;return A;}
const int INF=0x3f3f3f3f;

map<int,int> mp;
set<int> st;

int n,q,m,k;
int a[300005],b[300005];
int f[300005],g[300005];
int M[3005][3005];
char str[300005];

int h[300005],nxt[600005],to[600005],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

int main(){
	scanf("%d%s",&n,str+1);
	F(i,1,n){
		if(i==1||str[i-1]!=str[i]) {a[++m]=str[i]=='G'?1:0; b[m]=1;}
		else ++b[m];
	}
	if(m==1){
		if(a[1]==1) printf("%d\n",b[1]);
		else printf("0\n");
		return 0;
	}
	int cnt=0,mx=0;
	F(i,1,m) if(a[i]) ++cnt, mx=max(mx,b[i]);
	if(cnt==1) return printf("%d\n",mx),0;
	if(cnt==2){
		F(i,1,m) if(i>=2&&!a[i]&&a[i-1]&&a[i+1]){
			if(b[i]==1) printf("%d\n",b[i-1]+b[i+1]);
			else printf("%d\n",max(b[i-1],b[i+1])+1);
		}
		return 0;
	}
	int ans=0;
	F(i,1,m){
		if(i>=2&&!a[i]&&a[i-1]&&a[i+1]){
			if(b[i]==1) ans=max(ans,b[i-1]+b[i+1]+1);
			else ans=max(ans,max(b[i-1],b[i+1])+1);
		}
	}
	printf("%d\n",max(mx+1,ans));
	return 0;
}