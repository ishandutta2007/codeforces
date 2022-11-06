#include <bits/stdc++.h>
using namespace std;
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define coord_comp(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define v_index(v, x) (lower_bound(all(v),x)-(v).begin())
typedef pair<int,int> pp;
typedef long long ll;
void read(int& x){ scanf("%d",&x); }
template<typename T1,typename T2>
void read(pair<T1,T2>& p){ read(p.first); read(p.second); }
template<typename T,typename... Args>
void read(T&a,Args&...b){ read(a); read(b...); }

int maxmatch[1010][1010];
int n,m;

char a[1010];
char b[1010];
int k;

struct tree_ {
	static const int M=1024;
	int tree[M*2];
	tree_(){
		for(int i=0; i<M*2;++i) tree[i]=-2e9;
	}
	int rangemax(int a,int b){
		int ret=-2e9;
		a+=M; b+=M;
		while(a<=b){
			if(a%2==1) ret=max(ret, tree[a++]);
			if(b%2==0) ret=max(ret, tree[b--]);
			a/=2; b/=2;
		}
		return ret;
	}
	void upd(int p,int v){
		p+=M;
		while(p) tree[p]=max(tree[p],v), p>>=1;
	}
} T[2010][11];

int dp[1010][1010][11];

int main(){
	read(n,m,k);
	scanf("%s%s",1+a,1+b);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j){
		if(a[i]==b[j]) maxmatch[i][j] = maxmatch[i-1][j-1]+1;
	}
	for(int i=0; i<=n; ++i) for(int j=0; j<=m; ++j){
		T[i-j+m][0].upd(i,-i);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			for(int t=1;t<=k;++t){
				dp[i][j][t]=max(dp[i-1][j][t], dp[i][j-1][t]);
				int pt=i-j+m;
				int mm=maxmatch[i][j];
				dp[i][j][t]=max(dp[i][j][t],
					T[pt][t-1].rangemax(i-mm,i-1)+i);
				T[pt][t].upd(i,dp[i][j][t]-i);
			}
		}
	}
	printf("%d\n", dp[n][m][k]);
	return 0;
}