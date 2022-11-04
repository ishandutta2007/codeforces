#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = (int) 1e9 + 7;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}*/

using namespace std;


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string str;
    cin >> str;

    string aux;
    for(auto it : str) {
        if(it != 'a') {
            aux.push_back(it);
        }
    }

    int sz = aux.size();
    if(sz & 1) {
        cout << ":(";
        return 0;
    }

    for(i = 0; i < sz / 2; i++) {
        if(aux[i] != aux[sz / 2 + i]) {
            cout << ":(";
            return 0;
        }
    }

    string sol;
    int cnt = 0;

    for(auto it : str) {
        cnt += (it != 'a');
        if(cnt > sz / 2) {
            if(it == 'a') {
                cout << ":(";
                return 0;
            }
        }
        else {
            sol.push_back(it);
        }
    }

    cout << sol;

    return 0;
}