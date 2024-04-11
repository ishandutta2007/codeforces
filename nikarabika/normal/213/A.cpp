#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 200 + 85 - 69;
int n;
int c[maxn], h[maxn], in[maxn], ind[maxn];
vector<int> v[maxn];

int bfs(){
	set<pie> s;
	memset(ind, 0, sizeof ind);
	memset(h, 0, sizeof h);
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= n; j++){
			if(c[j] == i and ind[j] == in[j]){
				s.insert(MP(i, j));
				h[j] = i;
			}
		}
	}
	while(s.size()){
		int x = s.begin()->R;
		s.erase(s.begin());
		for(auto y : v[x]){
			ind[y]++;
			if(ind[y] == in[y]){
				h[y] = h[x] + ((c[y] - c[x] + 3) % 3);
				s.insert(MP(h[y], y));
			}
		}
	}
	int Max = 0;
	for(int i = 1; i <= n; i++)
		Max = max(Max, h[i] - 1);
	return Max;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	for(int i = 1; i <= n; i++){
		cin >> in[i];
		for(int j = 0; j < in[i]; j++){
			int x;
			cin >> x;
			v[x].PB(i);
		}
	}
	int ans = 1e9;
	for(int b = 1; b <= 3; b++){
		ans = min(ans, bfs());
		for(int i = 1; i <= n; i++)
			c[i] = ((c[i] + 1) % 3) + 1;
	}
	cout << ans + n << endl;
	return 0;
}