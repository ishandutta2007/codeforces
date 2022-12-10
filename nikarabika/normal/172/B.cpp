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

const int maxn = 100000;
int pos[maxn];
int a, b, r0, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b >> m >> r0;
	memset(pos, -1, sizeof pos);
	pos[r0] = 0;
	for(int i = 1; 1; i++){
		r0 = (a * r0 + b) % m;
		if(pos[r0] != -1){
			cout << i - pos[r0];
			return 0;
		}
		pos[r0] = i;
	}
	return 0;
}