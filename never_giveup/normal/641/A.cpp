#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10, inf = 1e9 + 1;

int n, m, q[maxn];

int p[maxn];

bool v[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        char c;
        cin >> c;
        if (c == '>')
            p[i] = 1;
        else
            p[i] = -1;
    }
    for (int i = 0; i < n; i++)
        cin >> q[i];
    int ind = 0;
    while (1){
        if (v[ind]){
            cout << "INFINITE";
            return 0;
        }
        v[ind] = 1;
        ind = ind + p[ind] * q[ind];
        if (ind < 0 || ind >= n){
            cout << "FINITE";
            return 0;
        }
    }
}