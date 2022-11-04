#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 92

using namespace std;

bool f[100000];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    int a = 1, b = 1;
    f[1] = 1;
    while(b <= n) {
        int aux = b;
        f[b] = 1;
        b = a + b;
        a = aux;
    }
    for(i = 1; i <= n; i++) {
        if(f[i] == 1)
            cout << "O";
        else
            cout << "o";
    }
    //cin.close();
    //cout.close();
    return 0;
}