//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "First" << endl;
        for (int i = 0; i < n + n; i++)
            cout << (i % n) + 1 << ' ';
        cout << endl;
    }
    else {
        cout << "Second" << endl;
        vector<int> vec[n],
            dom[n];
        int mark[n] = {0};
        for (int i = 1; i <= n + n; i++) {
            int col;
            cin >> col, col--;
            vec[i % n].PB(col);
            dom[col].PB(i);
        }
        for (int i = 0; i < n; i++)
            if (!mark[i]) {
                int d = i;
                int prv = dom[d][0];
                do {
                    mark[d] = 1 + (dom[d][0] == prv);
                    int cur = dom[d][0] ^ dom[d][1] ^ prv;
                    int rem = cur % n;
                    d ^= vec[rem][0] ^ vec[rem][1];
                    prv = cur <= n ? cur + n : cur - n;
                } while (d != i);
            }
        LL sum = 0;
        for (int i = 0; i < n; i++)
            sum += dom[i][mark[i] - 1];
        if (sum % (2 * n) == 0)
            for (int i = 0; i < n; i++)
                cout << dom[i][mark[i] - 1] << ' ';
        else
            for (int i = 0; i < n; i++)
                cout << dom[i][mark[i] & 1] << ' ';
        cout << endl;
    }
	return 0;
}