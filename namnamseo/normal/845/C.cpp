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

int n;
pp data[200010];

int ending[2];

int main()
{
	read(n);
	for(int i=0; i<n; ++i){
		int x, y; read(x, y);
		data[i]={x, y};
	}
	sort(data, data+n);
	ending[0]=ending[1]=-1;
	for(int i=0; i<n; ++i){
		int l, r; tie(l, r)=data[i];
		if(ending[0] < l) ending[0]=r;
		else if(ending[1]<l) ending[1]=r;
		else {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}