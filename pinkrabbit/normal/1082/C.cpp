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
set<int> st;

int n,m;
LL Ans;

vector<int> ve[100005];
int p[100005];

bool cmp(int i,int j){return i>j;}
bool cmp2(int i,int j){return ve[i].size()>ve[j].size();}

int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		ve[x].push_back(y);
	}
	F(i,1,m) sort(ve[i].begin(),ve[i].end(),cmp);
	F(i,1,m) F2(j,1,ve[i].size()) ve[i][j]+=ve[i][j-1];
	F(i,1,m) p[i]=i;
	sort(p+1,p+m+1,cmp2);
	F(i,1,n){
		LL Sum=0;
		F(j,1,m){
			if(ve[p[j]].size()<i)
				break;
			if(ve[p[j]][i-1]>0)Sum+=ve[p[j]][i-1];
		}
		Ans=max(Ans,Sum);
	}
	printf("%lld\n",Ans);
	return 0;
}