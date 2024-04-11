#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;

int main()
{
    fastio;

    int t; cin >> t;
    while (t--) {
        int a, b, c, d; 
        cin >> a >> b >> c >> d;

        if ((a+b) % 2) {
            // negative
            if (a == 0 && d == 0) {
                cout << "Tidak Ya Tidak Tidak\n";
            } else if (b == 0 && c == 0) {
                cout << "Ya Tidak Tidak Tidak\n";
            } else {
                cout << "Ya Ya Tidak Tidak\n";
            }
        } else {
            // positive
            if (a == 0 && d == 0) {
                cout << "Tidak Tidak Ya Tidak\n";
            } else if (b == 0 && c == 0) {
                cout << "Tidak Tidak Tidak Ya\n";
            } else {
                cout << "Tidak Tidak Ya Ya\n";
            }
        }
    }
}