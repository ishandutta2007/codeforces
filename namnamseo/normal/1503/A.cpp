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

char a[maxn], b[maxn];

bool Work() {
	int la = 0, lb = 0;
	rrep(i, n) {
		if (s[i] == '1') {
			if (min(la, lb) >= 2) {
				a[i] = b[i] = ')';
				--la; --lb;
			} else {
				a[i] = b[i] = '(';
				++la; ++lb;
			}
		} else {
			if (la >= lb) {
				a[i] = ')'; --la;
				b[i] = '('; ++lb;
			} else {
				a[i] = '('; ++la;
				b[i] = ')'; --lb;
			}
		}
		if (la < 0 || lb < 0) return false;
	}
	if (la != lb) return false;
	if (la % 2 || lb % 2) return false;
	int tmp = la;
	for (int i=n; 1<=i && tmp; --i) {
		if (a[i] == '(') --la; else ++la;
		if (b[i] == '(') --lb; else ++lb;

		if (s[i] == '1' && a[i] == '(' && la > 0 && lb > 0) {
			tmp -= 2;
			a[i] = ')';
			b[i] = ')';
		}
	}
	la = lb = 0;
	rrep(i, n) {
		if (a[i] == ')') --la; else ++la;
		if (b[i] == ')') --lb; else ++lb;
		if (la < 0 || lb < 0) return false;
	}
	if (la || lb) return false;
	return true;
}

int main()
{
	cppio();
	int tc;
	cin >> tc;
rrep(tci, tc) {
	cin >> n;
	cin >> (s+1);

	if (Work()) {
		a[n+1] = b[n+1] = 0;
		cout << "YES\n" << (a+1) << '\n' << (b+1) << '\n';
	} else {
		cout << "NO\n";
	}
}

	return 0;
}