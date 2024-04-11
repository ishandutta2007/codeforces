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
char s[maxn];

void Work() {
	cin >> (s+1);
	n = strlen(s+1);

	int c[2] = {0, 0};
	rrep(i, n) c[s[i]-'0']++;
	if (!c[0]) {
		cout << 0 << '\n';
		return;
	}

	int zrun = 0;
	for (int i=1, j; i<=n;) {
		if (s[i] == '1') { ++i; continue; }
		++zrun;
		for (j=i+1; j<=n && s[j] == '0'; ++j);
		i = j;
	}
	if (zrun == 1) {
		cout << 1 << '\n';
	} else {
		cout << 2 << '\n';
	}
}

int main()
{
	cppio();
	int tc; cin >> tc;
rrep(tci, tc) {
	Work();
}
	return 0;
}