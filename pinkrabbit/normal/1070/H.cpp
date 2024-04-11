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

int tr[256];

int n,m;
char qs[10005][10];
char str[50005][10];
int pos[50005];

int nxt[500005][37],mk[500005],cn[500005],tot;

int ins(char*str){
	int now=0;
	for(int i=0;str[i];++i){
		if(!nxt[now][tr[str[i]]]) nxt[now][tr[str[i]]]=++tot;
		now=nxt[now][tr[str[i]]];
	} return now;
}

void go(char*str,int id){
	int len=strlen(str);
	F2(i,0,len){
		int now=0;
		F2(j,i,len){
			if(!nxt[now][tr[str[j]]]) break;
			now=nxt[now][tr[str[j]]];
			if(mk[now]!=id) mk[now]=id, ++cn[now];
		}
	}
}

int main(){
	
	F(i,'a','z') tr[i]=i-'a';
	F(i,'0','9') tr[i]=i-'0'+26;
	tr['.']=36;
	
	scanf("%d",&n);
	F(i,1,n) scanf("%s",qs[i]);
	scanf("%d",&m);
	F(i,1,m){
		scanf("%s",str[i]);
		pos[i]=ins(str[i]);
	}
	F(i,1,n){
		go(qs[i],i);
	}
	qs[0][0]='-', qs[0][1]='\0';
	F(i,1,m){
		printf("%d %s\n",cn[pos[i]],qs[mk[pos[i]]]);
	}
	return 0;
}