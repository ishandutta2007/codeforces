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

const int maxn = int(1e5) + 10;

int n, k;
char s[maxn];
int st[26];
char ans[maxn];

int main()
{
	cppio();
	int tc; cin >> tc;

rep(tci, tc) {
	cin >> n >> k >> s;
	if (n%k) { cout << "-1\n"; continue; }
	fill(st, st+26, 0);
	rep(i, n) st[s[i]-'a']++;

	{
		bool ok = true;
		rep(i, 26) if (st[i]%k) { ok = 0; break; }
		if (ok) {
			cout << s << '\n';
			continue;
		}
	}

	int yoyu = 0;
	int b = n-1;
	char rc = -1;
	while (b >= 0) {
		--st[s[b]-'a'];
		for (int i=s[b]-'a'+1; i<26; ++i) {
			++st[i];
			int need = 0;
			rep(j, 26) {
				need += (k - st[j]%k)%k;
			}
			--st[i];
			if (need <= yoyu) {
				rc = i;
				break;
			}
		}
		if (rc != -1) break;
		++yoyu;
		--b;
	}

	if (rc == -1) { cout << "-1\n"; continue; }

	copy(s, s+b, ans);
	ans[b] = 'a'+rc;
	++st[rc];
	rep(i, 26) {
		int t = (k - st[i]%k) % k;
		st[i] = t;
		yoyu -= t;
	}
	st[0] += yoyu;

	for (int i=b+1; i<n; ++i) {
		rep(j, 26) if (st[j]) {
			ans[i] = 'a'+j;
			--st[j];
			break;
		}
	}

	ans[n] = 0;
	cout << ans << '\n';
}

	return 0;
}