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

int n, m;
char s[maxn];
char t[maxn];

int main()
{
	cppio();
	int tc; cin >> tc;
for(;tc--;) {
	cin >> n >> m >> (s+1);
	for (;m--;) {
		bool df = 0;
		for (int i=1; i<=n; ++i) {
			if (s[i] == '1') {
				t[i] = '1';
				continue;
			}
			if ((s[i-1]=='1') + (s[i+1]=='1') == 1) {
				t[i] = '1';
				df = 1;
			} else {
				t[i] = '0';
			}
		}
		if (!df) break;
		copy(t+1, t+n+1, s+1);
	}
	cout << (s+1) << '\n';
}


	return 0;
}