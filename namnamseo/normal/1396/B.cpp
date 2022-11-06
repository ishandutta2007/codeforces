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

const int maxn = int(2e5) + 10;
int n;
int a[maxn];

int main()
{
	cppio();

	int tc; cin >> tc;
for(;tc--;) {

	cin >> n;
	rrep(i, n) cin >> a[i];

	if (n == 1) {
		cout << "T\n";
		continue;
	} else if (n == 2) {
		if (a[1] == a[2]) {
			cout << "HL\n";
		} else {
			cout << "T\n";
		}
		continue;
	}

	int mx = max_element(a+1, a+n+1) - a;
	int s = accumulate(a+1, a+n+1, 0);
	if (a[mx] > s-a[mx]) {
		cout << "T\n";
	} else {
		cout << ((s%2==1) ? "T" : "HL") << '\n';
	}
}

	return 0;
}