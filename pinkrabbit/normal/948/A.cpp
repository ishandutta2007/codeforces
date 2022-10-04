#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define ll long long
#define ld double
using namespace std;
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline ll Gcd(ll X,ll Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int base,ll exp,int _mod){int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
const int INF=0x3f3f3f3f;

int n,m,ok=1;
char str[501][505];

int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n){
		scanf("%s",str[i]);
	}
	F(i,1,n){
		F2(j,0,m){
			if(str[i][j]=='S'&&(str[i-1][j]=='W'||str[i][j-1]=='W'||str[i+1][j]=='W'||str[i][j+1]=='W')) ok=0;
		}
	}
	if(ok){
		puts("Yes");
		F(i,1,n){
			F2(j,0,m){
				printf("%c",str[i][j]=='.'?'D':str[i][j]);
			}
			puts("");
		}
	}
	else puts("No");
	return 0;
}