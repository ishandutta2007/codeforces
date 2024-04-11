#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e6;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, a, b;
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    int nra = -1, nrb = -1;
    for(i = 0; i * a <= n; i++) {
        if((n - i * a) % b == 0) {
            nra = i;
            nrb = (n - i * a) / b;
            break;
        }
    }
    if(nra == -1) {
        cout << -1;
        return 0;
    }
    i = 1;
    while(i <= n) {
        int sz;
        if(nra > 0) {
            sz = a;
            nra--;
        }
        else {
            sz = b;
            nrb--;
        }
        int j = i;
        while(j < sz + i - 1) {
            cout << j + 1 << " ";
            j++;
        }
        cout << i << " ";
        i += sz;
    }
    //cin.close();
    //cout.close();
    return 0;
}