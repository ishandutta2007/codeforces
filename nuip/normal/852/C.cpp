#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int n;
int a[50010];
pii pt[50010];
int ans[50010];

int main() {
	cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n) pt[i] = mp(-a[i]-a[(i+1)%n], i);
	sort(pt, pt + n);
	reverse(pt, pt + n);
	rep(i, n) ans[pt[i].se] = i;
	rep(i, n) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');

	return 0;
}