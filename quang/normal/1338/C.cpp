#include <bits/stdc++.h>

using namespace std;

long long get1(long long u) {
    vector<int> res;
    while (u) {
        res.push_back(u % 2);
        u /= 2;
    }
    res.push_back(0);
    for (int i = 0; i < res.size(); i += 2) {
        if (res[i] == 1 && res[i + 1] == 0) {
            swap(res[i], res[i + 1]);
        } else if (res[i] == 0 && res[i + 1] == 1) {
            res[i] = res[i + 1] = 1;
        } else if (res[i] == 1 && res[i + 1] == 1) {
            res[i] = 1;
            res[i + 1] = 0;
        }
    }
    reverse(res.begin(), res.end());
    long long ans = 0;
    for (int u : res) {
        ans = ans * 2ll + u;
    }
    return ans;
}


long long get2(long long u) {
    vector<int> res;
    while (u) {
        res.push_back(u % 2);
        u /= 2;
    }
    res.push_back(0);
    for (int i = 0; i < res.size(); i += 2) {
        if (res[i] == 1 && res[i + 1] == 0) {
            res[i] = res[i + 1] = 1;
        } else if (res[i] == 0 && res[i + 1] == 1) {
            res[i] = 1;
            res[i + 1] = 0;
        } else if (res[i] == 1 && res[i + 1] == 1) {
            res[i] = 0;
            res[i + 1] = 1;
        }
    }
    reverse(res.begin(), res.end());
    long long ans = 0;
    for (int u : res) {
        ans = ans * 2ll + u;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        long long n;
        cin >> n;
        n--;
        long long id = n % 3;
        n /= 3ll;
        for (int i = 0; i <= 60; i += 2) {
            if (n >= (1ll << i)) {
                n -= (1ll << i);
            } else {
                n += (1ll << i);
                break;
            }
        }
        if (id == 0) cout << n << '\n';
        else if (id == 1) cout << get1(n) << '\n';
        else cout << get2(n) << '\n';
    }

    return 0;
}