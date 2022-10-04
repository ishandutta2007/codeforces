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
set<int,int> st;

int n,q,m,k,Ans;
int a[300005],b[300005];
int f[300005],g[300005];
int M[3005][3005];
char str[300005];

int h[300005],nxt[600005],to[600005],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

const int dx[4]={0,0,-1,1};
const int dy[4]={1,-1,0,0};

int z[256];

LL abs(LL x){return x>0?x:-x;}

int main(){
	z['U']=0;
	z['D']=1;
	z['L']=2;
	z['R']=3;
	int X,Y;
	scanf("%d%s",&n,str+1); Ans=n;
	scanf("%d%d",&X,&Y);
	if(abs(X)+abs(Y)>n) prts("-1");
	if(((X&1)^(Y&1))!=(n&1)) prts("-1");
	f[n+1]=g[n+1]=0;
	dF(i,n,1){
		f[i]=f[i+1]+dx[z[str[i]]];
		g[i]=g[i+1]+dy[z[str[i]]];
	}
//	F(i,1,n) printf("(%d,%d)\n",f[i],g[i]);
	if(f[1]==X&&g[1]==Y){
		prts("0");
	}
	int x=0,y=0;
	F(i,1,n){
		int l=i+1, r=n+1, ans=-1;
		while(l<=r){
			int mid=l+r>>1;
			if((LL)abs(x+f[mid]-X)+(LL)abs(y+g[mid]-Y)<=mid-i) ans=mid, r=mid-1;
			else l=mid+1;
		}
		if(ans!=-1 && Ans>ans-i) Ans=ans-i;
		x+=dx[z[str[i]]];
		y+=dy[z[str[i]]];
	} printf("%d\n",Ans);
	return 0;
}