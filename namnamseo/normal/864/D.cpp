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
int a[200010];

int cnt[200010];
bool used[200010];
set<int> u;

int main()
{
	read(n);
	int ans = n;
	for(int i=1; i<=n; ++i){
		read(a[i]);
		if(1 <= a[i] && a[i] <= n) ans -= !cnt[a[i]]++;
	}
	printf("%d\n", ans);
	for(int i=1; i<=n; ++i) if(!cnt[i]) u.insert(i);
	auto poll = [&](){
		printf("%d ", *u.begin());
		u.erase(u.begin());
	};
	for(int i=1; i<=n; ++i){
		int t=a[i];
		if(1 <= t && t <= n){
			if(u.empty() || cnt[t] == 1){
				printf("%d ", t); continue;
			}
			if(used[t]){
				poll(); --cnt[t]; continue;
			}
			if(t <= *u.begin()){
				used[t] = 1;
				printf("%d ", t);
			} else {
				poll(); --cnt[t];
			}
		} else poll();
	}
	return 0;
}