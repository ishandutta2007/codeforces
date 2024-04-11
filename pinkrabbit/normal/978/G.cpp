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

int n,q;
int s[105],d[105],c[105],p[105];
int a[105];
int A[105];

bool cmp(int p1,int p2){return d[p1]<d[p2];}

int main(){
	scanf("%d%d",&n,&q);
	F(i,1,q) scanf("%d%d%d",s+i,d+i,c+i), p[i]=i, a[d[i]]=i, p[i]=i;
	sort(p+1,p+q+1,cmp);
	int now=1;
	F(i,1,n){
		if(a[i]){
			if(c[a[i]]==0)
				A[i]=q+1;
			else return 0*puts("-1");
		}
		else{
			F(j,1,q){
				int k=p[j];
				if(c[k]&&i>=s[k]) {A[i]=k, --c[k]; break;}
			}
		}
	}
	F(i,1,n) printf("%d ",A[i]);
	return 0;
}