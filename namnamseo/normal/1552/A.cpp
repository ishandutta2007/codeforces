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
char s[maxn];
char t[maxn];

void Work() {
	cin >> n;
	cin >> (s+1);
	copy(s+1, s+n+1, t+1);
	sort(t+1, t+n+1);
	int df = 0;
	rrep(i, n) if (s[i] != t[i]) ++df;
	cout << df << '\n';

	;
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