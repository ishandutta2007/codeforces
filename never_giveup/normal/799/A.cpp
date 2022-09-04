#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

const ld EPS = 1e-9;

const ll llinf = 1e18 + 100;

const int maxn = 2e5 + 100, inf = 1e9 + 100;



int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
	    #ifndef STR
	    //ifstream cin("a.in");
	    //ofstream cout("a.out");
	    //freopen("a.in", "r", stdin);
	    //freopen("a.out", "w", stdout);
    	    #endif // STR
    #endif // ONPC
    ios::sync_with_stdio(0);
    int n, t, k, d;
    cin >> n >> t >> k >> d;
    int l = -1, r = 1000000;
    while (r - l > 1){
        int m = (l + r) / 2;
        if (m / t * k + max(0, (m - d) / t * k) >= n)
            r = m;
        else
            l = m;
    }
    int x = r;
    l = -1, r = 1000000;
    while (r - l > 1){
        int m = (l + r) / 2;
        if (m / t * k >= n)
            r = m;
        else
            l = m;
    }

    if (x != r)
        cout << "YES";
    else
        cout << "NO";
}