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

int tenth[10]={1};

int main()
{
	for(int i=1; i<=6; ++i) tenth[i]=tenth[i-1]*10;
	int x; read(x);
	int ans=1e9;
	for(int t=0; t<1000000; ++t){
		int a[6];
		for(int i=0; i<6; ++i){
			a[i]=t/tenth[i]%10;
		}
		if(accumulate(a, a+3, 0) == accumulate(a+3, a+6, 0)){
			int s=0;
			for(int i=0; i<6; ++i){
				s += (t/tenth[i]%10 != x/tenth[i]%10);
			}
			ans=min(ans, s);
		}
	}
	printf("%d\n", ans);
	return 0;
}