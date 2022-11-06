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

char s[maxn];
char t[maxn];
int n, m;

int ml[maxn], mr[maxn];

int main()
{
	cppio();
	cin >> n >> m;
	cin >> (s+1) >> (t+1);

	// l match
	for (int i=1, j=1; i<=m; ++i) {
		while (s[j] != t[i]) ++j;
		ml[i] = j++;
	}

	// r match
	for (int i=m, j=n; i>=1; --i) {
		while (s[j] != t[i]) --j;
		mr[i] = j--;
	}

	int ans = 1;
	for (int i=1; i<m; ++i) {
		ans = max(ans, mr[i+1]-ml[i]);
	}

	cout << ans << '\n';

	return 0;
}