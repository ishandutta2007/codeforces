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
	int n;
	read(n);
	vector<int> s; s.resize(2*n);
	for(int& x:s) read(x);
	sort(all(s));
	if(s[n-1]<s[n]) puts("YES");
	else puts("NO");
	return 0;
}