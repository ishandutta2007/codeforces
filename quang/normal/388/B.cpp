#include <bits/stdc++.h>
#define Task "B"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int CS = 30;

int k;
int res[1001][1001], a[40][40];

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> k;
    cout << CS * CS + 2 << endl;
    for(int i = 0; i < CS; i++)
        for(int j = 0; j < CS; j++) a[i][j] = i * CS + j + 3;
    for(int i = 0; i < CS - 1; i++)
    for(int j = 0; j < CS; j++) {
        res[a[i][j]][a[i + 1][j]] = res[a[i + 1][j]][a[i][j]] = 1;
        if(i >= j)
            res[a[i][j]][a[i + 1][j + 1]] = res[a[i + 1][j + 1]][a[i][j]] = 1;
    }
    for(int i = 0; i < CS; i++)
        res[2][a[CS - 1][i]] = res[a[CS - 1][i]][2] = 1;
    for(int i = 0; i <= 30; i++)
        if(k & (1 << i))
            res[1][a[0][CS - i - 1]] = res[a[0][CS - i - 1]][1] = 1;
    for(int i = 1; i <= CS * CS + 2; i++, cout << endl)
        for(int j = 1; j <= CS * CS + 2; j++) cout << (res[i][j]? "Y" : "N");
    return 0;
}