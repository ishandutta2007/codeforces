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

char A[50][50], ans1[50][50], ans2[50][50];
void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < m; j++){
			A[i][j] = s[j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			ans1[i][j] = ((i + j) % 2 ? 'R' : 'W');
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			ans2[i][j] = ((i + j) % 2 == 0 ? 'R' : 'W');
		}
	}
	
	bool f1 = false, f2 = false;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(A[i][j] != '.' && ans1[i][j] != A[i][j]) f1 = true;
		}
	}	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(A[i][j] != '.' && ans2[i][j] != A[i][j]) f2 = true;
		}
	}
	if(!f1){
		cout << "YES" << endl;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cout << ans1[i][j];
			}
			cout << endl;
		}
		return;
	}	
	if(!f2){
		cout << "YES" << endl;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cout << ans2[i][j];
			}
			cout << endl;
		}
		return;
	}
	cout << "NO" << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}