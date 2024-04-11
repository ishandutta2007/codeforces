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

int q;
set<int> St[100001];

int main(){
	int opt,x,y,z;
	scanf("%d",&q);
	F(i,1,q){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d",&x);
			for(int j=1;j*j<=x;++j) if(x%j==0){
				St[j].insert(x);
				St[x/j].insert(x);
			}
		}
		else{
			scanf("%d%d%d",&x,&y,&z);
			z-=x;
			if(z<=0||x%y!=0||St[y].size()==0) {puts("-1"); continue;}
			set<int>::iterator it=St[y].begin();
			if(*it>z) {puts("-1"); continue;}
			//v%y==0 , St[y], v<=z , v^x (max)
			int now=0;
			dF(j,17,0){
				if((x>>j)&1){
					int tmp=*St[y].lower_bound(now);
					if(tmp<=z&&(tmp&(~((1<<j)-1)))==now) ;
					else now|=(1<<j);
				}
				else{
					int tmp=*St[y].lower_bound(now|(1<<j));
					if(tmp<=z&&(tmp&(~((1<<j)-1)))==(now|(1<<j))) now|=(1<<j);
					else ;
				}
			}
			printf("%d\n",now);
		}
	}
	return 0;
}