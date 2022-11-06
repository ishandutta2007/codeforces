#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

int n;
int a[100010];

int main()
{
	cppio();
	int tc; cin >> tc;
for(;tc--;) {
	cin >> n;
	rrep(i, n) cin >> a[i];

	int X = 0;
	rrep(i, n) X ^= a[i];

	if (!X) {
		cout << "DRAW\n";
		continue;
	}

	int b = 30;
	for(;;--b) if (X&(1<<b)) break;

	int c1 = 0, c0 = 0;
	rrep(i, n) ((a[i]&(1<<b))?c1:c0)++;

	if (c1%4 == 3 && c0%2 == 0) {
		cout << "LOSE\n";
	} else {
		cout << "WIN\n";
	}
}
	return 0;
}