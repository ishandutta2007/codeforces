#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-8
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

int n;
int a[800][800];
int p[800];

int main() {
    ios::sync_with_stdio(false);
    //freopen("restore.in", "r", stdin);
    //freopen("restore.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
    	p[i] = -1;
    }
    for (int i = 1; i < 2 * n; i++) {
    	for (int j = 0; j < i; j++) {
    		cin >> a[i][j];
    	}
    }

    for (int i = 0; i < n; i++) {
    	int bj = -1;
    	int bk = -1;
    	int bv = -INF;

    	for (int j = 1; j < 2 * n; j++) {
    		for (int k = 0; k < j; k++) {
    			if (a[j][k] > bv && p[j] == -1 && p[k] == -1) {
    				bv = a[j][k];
    				bj = j;
    				bk = k;
    			}
    		}
    	}

    	p[bj] = bk;
    	p[bk] = bj;
    }

    for (int i = 0; i < 2 * n; i++) {
    	cout << p[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}