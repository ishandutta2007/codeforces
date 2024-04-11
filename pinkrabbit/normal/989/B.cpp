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

int n,p;
char str[2005];
int a[2005],b[2005],c[2005];

int main(){
	scanf("%d%d",&n,&p);
	scanf("%s",str+1);
	F(i,1,n){
		if(str[i]=='1')
			a[i%p]=1;
		if(str[i]=='0')
			b[i%p]=1;
		if(str[i]=='.')
			++c[i%p];
	}
	int ok=0,j=-1;
	F2(i,0,p){
		if(c[i]>1)
			ok=1,j=i;
		if(a[i]&&b[i])
			ok=2;
		if(a[i]&&c[i])
			ok=3,j=i;
		if(b[i]&&c[i])
			ok=4,j=i;
	}
	if(!ok) return 0*puts("NO");
	if(ok==1){
		int k=0;
		F(i,1,n){
			if(str[i]!='.') putchar(str[i]);
			else{
				if(i%p==j) putchar(k+'0'), k^=1;
				else putchar('0');
			}
		}
	}
	if(ok==2){
		F(i,1,n)
			if(str[i]!='.') putchar(str[i]);
			else putchar('0');
	}
	if(ok==3){
		F(i,1,n)
			if(str[i]!='.') putchar(str[i]);
			else putchar('0');
	}
	if(ok==4){
		F(i,1,n)
			if(str[i]!='.') putchar(str[i]);
			else putchar('1');
	}
	return 0;
}