#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define all(_x) _x.begin(), _x.end()
#define szof(_x) (int) _x.size()

using namespace std;
typedef long long LL;
const int MAXN = 105;

int n, k;
int arr[MAXN];
vector <pair <int, int> > actions;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < k; ++i) {
        int minn = 1e9, memmin = -1;
        int maxn = -1, memmax = -1;
        for (int j = 0; j < n; ++j) {
            if (minn > arr[j]) {
                minn = arr[j];
                memmin = j;
            }
            if (maxn < arr[j]) {
                maxn = arr[j];
                memmax = j;
            }
        }
        if (maxn - minn <= 1) {
            break;
        }
        arr[memmax]--;
        arr[memmin]++;
        actions.puba(mapa(memmax, memmin));
    }
    int minn = 1e9, memmin = -1;
    int maxn = -1, memmax = -1;
    for (int j = 0; j < n; ++j) {
        if (minn > arr[j]) {
            minn = arr[j];
            memmin = j;
        }
        if (maxn < arr[j]) {
            maxn = arr[j];
            memmax = j;
        }
    }
    cout << maxn - minn << " " << szof(actions) << endl;
    for (int i = 0; i < szof(actions); ++i) {
        cout << actions[i].ff + 1 << " " << actions[i].ss + 1 << endl;
    }
    return 0;
}