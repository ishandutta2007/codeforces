//sobskdrbhvk
//remember the flying, the bird dies ):(
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int col, row, id;
	cin >> col >> row >> id;
	id--;
	int dir = id & 1;
	id /= 2;
	cout << id / row + 1 << ' ' << id % row + 1 << ' ' << (dir ? 'R' : 'L') << endl;
	return 0;
}