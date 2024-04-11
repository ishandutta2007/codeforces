#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, pair<int, int> > myp;

#define MP make_pair
#define MYP(a, b, c) MP(a, MP(b, c))
#define L first
#define R second
#define XW L
#define X R.L
#define W R.R

const int maxn = 2e5;
int Max[maxn], n;
myp a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++){
		int x, w;
		cin >> x >> w;
		a[i] = MYP(x + w, x, w);
	}
	sort(a, a + n);
	Max[0] = 1;
	for(int i = 1; i < n; i++){
		myp temp = MYP(a[i].X - a[i].W, a[i].X, 1000000001);
		int x = upper_bound(a, a + n, temp) - a;
		Max[i] = (x == 0) ? Max[i - 1] : max(Max[x - 1] + 1, Max[i - 1]);
	}
	cout << Max[n - 1] << endl;
	return 0;
}