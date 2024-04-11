#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define inf (1LL << 60)

#define dbg(a) (cout << #a << ": " << (a) << endl);
#define dbg2(a, b) (cout << #a << ": " << (a) << ", " << #b << ": " << (b) << endl);
#define dbg3(a, b, c) (cout << #a << ": " << (a) << ", " << #b << ": " << (b) << ", " << #c << ": " << (c) << endl);
#define dbg4(a, b, c, d) (cout << #a << ": " << (a) << ", " << #b << ": " << (b) << ", " << #c << ": " << (c) << ", " << #d << ": " << (d) << endl);
#define dbg5(a, b, c, d, e) (cout << #a << ": " << (a) << ", " << #b << ": " << (b) << ", " << #c << ": " << (c) << ", " << #d << ": " << (d) << ", " << #e << ": " << (e) << endl);

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(int a, int b){return a + rng() % (b - a);}

using namespace std;

template<class T>
void print(vector<T> v){
	for(auto i : v){
		cout << i << ' ';
	}
	cout << endl;
}

int A[400002];
void solve(){
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin>>A[i];
	}
	int ans = 0;
	A[0] = A[n + 1] = 0;
	for(int i = 1; i <= n; i++){
		if(A[i] > A[i - 1] && A[i] > A[i + 1]){
			int g = max(A[i - 1], A[i + 1]);
			ans += A[i] - g;
			A[i] = g;
		}
	}
	for(int i = 1; i <= n + 1; i++){
		ans += abs(A[i] - A[i - 1]);
	}
	cout << ans << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}