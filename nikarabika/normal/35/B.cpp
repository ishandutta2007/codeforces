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

const int maxn = 35;
map<string, int> mp;
int n, m, q;
bool mark[maxn * maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> n >> m >> q;
	while(q--){
		int ty, fi, se;
		string id;
		cin >> ty;
		if(ty == +1){
			cin >> fi >> se >> id;
			fi--, se--;
			for(int pos = fi * m + se; pos < n * m; pos++)
				if(!mark[pos]){
					mark[pos] = true;
					mp[id] = pos + 1;
					break;
				}
		}
		else{
			cin >> id;
			if(mp[id] == 0)
				cout << "-1 -1\n";
			else
				mark[mp[id]-1] = false, cout << (mp[id] - 1) / m + 1 << ' ' << (mp[id] - 1) % m + 1 << '\n', mp[id] = 0;
		}
	}
	return 0;
}