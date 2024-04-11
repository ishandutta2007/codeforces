//sobskdrbhvk
//remember the flight, the bird dies ):(
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

const int maxn = 1e6 + 85 - 69;
int ans[maxn],
	sz[maxn],
	n, c;
vector<int> vec[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> c;
	for(int i = 0; i < n; i++){
		cin >> sz[i];
		for(int j = 0; j < sz[i]; j++){
			int x;
			cin >> x, x--;
			vec[i].PB(x);
		}
	}
	for(int i = 0; i+1 < n; i++){
		int ptr = 0;
		while(ptr < sz[i] and ptr < sz[i + 1] and vec[i][ptr] == vec[i + 1][ptr])
			ptr++;
		if(ptr == min(sz[i], sz[i + 1])){
			if(sz[i] > sz[i + 1]){
				cout << -1 << endl;
				return 0;
			}
			continue;
		}
		int c1 = vec[i][ptr],
			c2 = vec[i+1][ptr];
		if(c1 < c2){
			ans[c - c2]++;
			ans[c - c1]--;
		}
		else{
			ans[0]++;
			ans[c - c1]--;
			ans[c - c2]++;
			ans[c]--;
		}
	}
	for(int i = 0; i + 1 <= c; i++)
		ans[i + 1] += ans[i];
	for(int i = 0; i < c; i++)
		if(ans[i] == 0){
			cout << i << endl;
			return 0;
		}
	cout << -1 << endl;
	return 0;
}