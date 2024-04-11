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
int a[100005],b[100005],A[100005];
int v[100005],p[100005];
int fa[100005],sz[100005];
int ff(int x){return fa[x]?fa[x]=ff(fa[x]):x;}
int cnt;
multiset<int> St;
multiset<int>::iterator it;
int Anss,Ansi;

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i), b[i]=a[i];
	sort(b+1,b+n+1);
	F(i,1,n) A[i]=a[i]+1, a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	F(i,1,n) p[a[i]]=i;
	F(I,1,n){
		int i=p[I];
		v[i]=1;
		if(v[i-1]&&v[i+1]){
			cnt--; 
			int f1=ff(i-1), f2=ff(i+1), s1=sz[f1], s2=sz[f2];
			fa[i]=fa[f2]=f1;
			sz[f1]=s1+s2+1;
			it=St.lower_bound(s1);
			St.erase(it);
			it=St.lower_bound(s2);
			St.erase(it);
			St.insert(s1+s2+1);
		}
		else if(!v[i-1]&&!v[i+1]){
			cnt++;
			sz[i]=1;
			St.insert(1);
		}
		else{
			int f1;
			if(v[i-1]) f1=ff(i-1);
			else f1=ff(i+1);
			fa[i]=f1;
			it=St.lower_bound(sz[f1]);
			St.erase(it);
			sz[f1]++;
			St.insert(sz[f1]);
		}
		int s1=*St.begin();
		it=St.end(); --it;
		int s2=*it;
		if(s1==s2){
			if(Anss<St.size())
				Anss=St.size(), Ansi=i;
		}
	}
	printf("%d",A[Ansi]);
	return 0;
}