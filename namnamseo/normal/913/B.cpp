#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

vector<int> ch[1010];
int cc[1010];

int main()
{
    int n;
	read(n);
    for(int i=2; i<=n; ++i){
		int x; read(x); ++cc[x]; ch[x].pb(i);
    }
	for(int i=1; i<=n; ++i){
		if(!cc[i]) continue;
		int cnt=0;
		for(int j:ch[i]){
			if(!cc[j]) ++cnt;
		}
		if(cnt<3){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
    return 0;
}