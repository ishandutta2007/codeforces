#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

int bit[20], aux[20];

vector < pair <char, int> > sol;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    char ch;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 0; i < 10; i++) {
        bit[i] = -1;
    }
    for(i = 0; i < n; i++) {
        cin >> ch >> x;
        for(int j = 0; j < 10; j++) {
            if(ch == '|') {
                if(x & (1 << j)) {
                    bit[j] = 1;
                }
            }
            if(ch == '&') {
                if((x & (1 << j)) == 0) {
                    bit[j] = 0;
                }
            }
            if(ch == '^') {
                if(x & (1 << j)) {
                    if(bit[j] == 0)
                        bit[j] = 1;
                    else if(bit[j] == 1)
                        bit[j] = 0;
                    else
                        aux[j] ^= 1;
                }
            }
        }
    }
    int cur = 0;
    for(i = 0; i < 10; i++) {
        if(bit[i] == 1) {
            cur ^= (1 << i);
        }
    }
    sol.push_back({'|', cur});
    cur = 0;
    for(i = 0; i < 10; i++) {
        if(bit[i] != 0) {
            cur ^= (1 << i);
        }
    }
    sol.push_back({'&', cur});
    cur = 0;
    for(i = 0; i < 10; i++) {
        if(bit[i] == -1 && aux[i] == 1) {
            cur ^= (1 << i);
        }
    }
    sol.push_back({'^', cur});
    cout << sol.size() << "\n";
    for(auto it : sol) {
        cout << it.first << " " << it.second << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}