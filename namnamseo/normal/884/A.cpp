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

int main()
{
	int n, t;
	read(n, t);
	for(int d=1; d<=n; ++d){
		int x; read(x);
		t -= 86400-x;
		if(t<=0){
			printf("%d\n", d);
			break;
		}
	}
	return 0;
}