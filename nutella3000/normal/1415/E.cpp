#include <bits/stdc++.h>

using namespace std;


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double

const int inf = 1e15;

int f(int n, int p, int k) {
	return (n - p + 1 + k - 1) / k;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    //cout.precision(3);

    int n, k;
    cin >> n >> k;
    k++;

    k = min(k, n);


    vector<int> a(n);
    for(int i = 0;i < n;i++)
    	cin >> a[i];

    sort(all(a));

    int res = 0;
    for(int i = 0;i < n;i++) {
    	res += a[i] * (i / k);
    }

    int sum = 0;

    int new_res = res;

    for(int i = n - 1;i >= 1;i--) {
    	new_res = new_res - a[i] * (i / k);
    	int len = ((i - 1) / k + 1);

    	new_res += sum + len * a[i];
    	if (len == i / k) new_res -= sum;

    	//cout << new_res << endl;
    	//cout << new_res << endl;
    	chkmax(res, new_res);
    	sum += a[i];
    }
    cout << res;
}