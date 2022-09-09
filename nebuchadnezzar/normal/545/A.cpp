#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 105;

int n;

int arr[MAXN][MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }

    vector <int> ans;
    for (int i = 0; i < n; ++i) {
        bool flag = true;
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == 3 || arr[i][j] == 1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans.puba(i);
        }
    }

    cout << szof(ans) << endl;

    for (int i = 0; i < szof(ans); ++i) {
        cout << ans[i] + 1 << " ";
    }

    return 0;
}