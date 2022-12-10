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

int pos[1000000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> pos[i];
	sort(pos, pos + n);
	int r = lower_bound(pos, pos + n, c) - pos;
	int l = upper_bound(pos, pos + n, b) - pos;
	cout << r - l << endl;
	return 0;
}