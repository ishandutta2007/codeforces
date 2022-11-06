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

int n;
int arr[maxn];
int pos[maxn];
int ans[maxn];

int main()
{
	cppio();
	int tc; 
	cin >> tc;
rep(tci, tc) {
	cin >> n;
	rrep(i, n) {
		int j; cin >> j;
		arr[i] = j;
		pos[j] = i;
	}

	int last = n+1;
	int ai = 0;
	for (int i=n; 1<=i; --i) {
		if (last <= pos[i]) {
			continue;
		}
		int p = pos[i];
		for (int j=p; j<last; ++j) {
			ans[++ai] = arr[j];
		}
		last = p;
	}

	rrep(i, n) {
		cout << ans[i] << " \n"[i==n];
	}
}

	return 0;
}