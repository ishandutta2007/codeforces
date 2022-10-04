#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define ll long long
#define ld double
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline ll Gcd(ll X,ll Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int base,ll exp,int _mod){if(!(base%=_mod))return 0;int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){if(!(base%=_mod))return 0;ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
const int INF=0x3f3f3f3f;

int n;
char str[300006];
int c[300006], C[300006],K;long long Ans;

int main(){
	scanf("%d",&n);
	F(i,1,n) {
		scanf("%s",str+1);
		int l=strlen(str+1);
		int cnt=0,c2=0;
		F(j,1,l){
			if(str[j]=='(') ++cnt;
			else{
				if(cnt) --cnt;
				else ++c2;
			}
		}
		if(cnt&&c2) continue;
		if(cnt==0&&c2==0){
			++K;
		}
		else{
			if(cnt)
				++c[cnt],
				Ans+=C[cnt];
			else
				++C[c2],
				Ans+=c[c2];
		}
	} printf("%lld",Ans+(ll)K*K);
	return 0;
}