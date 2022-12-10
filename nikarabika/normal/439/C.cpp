//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e5 + 85 - 69;
vector<int> num[2];
int n, k, p;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> p;
	p = k - p;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		num[x & 1].PB(x);
	}
	if((sz(num[1]) & 1) != (p & 1) or sz(num[1]) < p or (sz(num[1]) - p) / 2 + sz(num[0]) < k - p){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	int p1 = 0, p0 = 0;
	for(int i = 0; i < k; i++){
		if(i < p){
			if(i != k - 1)
				cout << 1 << ' ' << num[1][p1++] << '\n';
			else{
				cout << sz(num[0]) + sz(num[1]) - p0 - p1 << ' ';
				while(p0 < sz(num[0]))
					cout << num[0][p0++] << ' ';
				while(p1 < sz(num[1]))
					cout << num[1][p1++] << ' ';
				cout << '\n';
			}
		}
		else{
			if(i != k - 1){
				if(p1 < sz(num[1]))
					cout << 2 << ' ' << num[1][p1++] << ' ' << num[1][p1++] << '\n';
				else
					cout << 1 << ' ' << num[0][p0++] << '\n';
			}
			else{
				cout << sz(num[0]) + sz(num[1]) - p0 - p1 << ' ';
				while(p0 < sz(num[0]))
					cout << num[0][p0++] << ' ';
				while(p1 < sz(num[1]))
					cout << num[1][p1++] << ' ';
				cout << '\n';
			}
		}
	}
	return 0;
}