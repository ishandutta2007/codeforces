#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 217
// 44

using namespace std;

const int MAXVAL = (int) 1e6;

int sp[MAXVAL + 1][10];
int g[MAXVAL + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, l, r, k, q;
    ios::sync_with_stdio(false);
    for(i = 1; i <= MAXVAL; i++) {
        for(j = 0; j < 10; j++) {
            sp[i][j] = sp[i - 1][j];
        }
        int aux = i;
        int prd = 1;
        while(aux > 0) {
            if(aux % 10 > 0)
                prd *= (aux % 10);
            aux /= 10;
        }
        if(i < 10)
            g[i] = i;
        else
            g[i] = g[prd];
        sp[i][g[i]]++;
    }
    cin >> q;
    while(q > 0) {
        q--;
        cin >> l >> r >> k;
        cout << sp[r][k] - sp[l - 1][k] << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}