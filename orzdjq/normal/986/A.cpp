#include<cmath>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#define LL long long
#define ll long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define big 20160116
#define INF 2147483647
#define pq priority_queue
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int Maxn=100005;
int n,m,k,s;
int dis[Maxn][105];
vector<int> G[Maxn];
int a[Maxn];
int tp[Maxn];
vector<int> S[105];
int main(){
	scanf("%d %d %d %d",&n,&m,&k,&s);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		S[a[i]].pb(i);
	}
	for (int i=0;i<m;i++){
		int u,v;scanf("%d %d",&u,&v);
		G[u].pb(v);G[v].pb(u);
	}
	for (int i=1;i<=k;i++){
		queue<int> Q;
		for (int j=1;j<=n;j++) dis[j][i]=-1;
		for (int j=0;j<S[i].size();j++){
			dis[S[i][j]][i]=0;
			Q.push(S[i][j]);
		}
		while (!Q.empty()){
			int x=Q.front();
			Q.pop();
			for (int j=0;j<G[x].size();j++){
				int v=G[x][j];
				if (dis[v][i]==-1){
					dis[v][i]=dis[x][i]+1;
					Q.push(v);
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		sort(dis[i]+1,dis[i]+1+k);
		int ans=0;
		for (int j=1;j<=s;j++){
			ans+=dis[i][j];
		}
		printf("%d ",ans);
	}
	return 0;
}