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
inline int Pow(int base,ll exp,int _mod){if(!(base%=_mod))return 0;int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){if(!(base%=_mod))return 0;ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
const int INF=0x3f3f3f3f;

int n,q;
int l[300001],r[300001],p[300001];
bool cmp(int p1,int p2){return l[p1]==l[p2]?r[p1]>r[p2]:l[p1]<l[p2];}

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d%d",l+i,r+i), p[i]=i;
	sort(p+1,p+n+1,cmp); r[0]=INF;
	int nowm=0;
	dF(i,n,1){
		if(r[p[nowm]]<=r[p[i]]) {printf("%d %d",p[nowm],p[i]); return 0;}
		if(r[p[i]]<r[p[nowm]]) nowm=i;
	} puts("-1 -1");
	return 0;
}