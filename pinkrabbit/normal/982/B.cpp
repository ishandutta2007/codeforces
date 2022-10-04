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

int n,w[200001];
char str[400005];
map<int,int> Mp;
set<int> St1,St2;

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",w+i), Mp[w[i]]=i, St1.insert(w[i]);
	scanf("%s",str+1);
	set<int>::iterator it;
	F(i,1,2*n){
		if(str[i]=='0'){
			it=St1.begin();
			printf("%d ",Mp[*it]);
			St2.insert(*it);
			St1.erase(it);
		}
		else{
			it=St2.end();
			--it;
			printf("%d ",Mp[*it]);
			St2.erase(it);
		}
	}
	return 0;
}