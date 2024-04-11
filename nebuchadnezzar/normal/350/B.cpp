#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define puba push_back
#define mapa make_pair

using namespace std;

vector <int> now, ans;
int n, type[100000], mas[100000], nums[100000], maxl;

int dfs(int v, int l) {
    //cout << v << " " << l << endl;
    if (nums[v] > 1) {
        if (maxl < l - 1) {
            maxl = l - 1;
            ans = now;
        }
        return 0;
    }
    now.puba(v + 1);
    if (mas[v] == -1) {
        if (maxl < l) {
            maxl = l;
            ans = now;
        }
        return 0;
    }
    if (nums[v] <= 1) {
        dfs(mas[v], l + 1);
    }
    return 0;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> type[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> mas[i];
        --mas[i];
        if (mas[i] >= 0) {
            ++nums[mas[i]];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (type[i] == 1) {
            now.clear();
            dfs(i, 1);
        }
    }

    cout << maxl << endl;

    reverse(ans.begin(), ans.end());

    for (int i = 0; i < (int) ans.size(); ++i) {
        cout << ans[i] << " ";
    }

    return 0;
}