#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

int fr[3];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> x;
        fr[x]++;
    }
    cout << min(fr[1], fr[2]) + (fr[1] - min(fr[1], fr[2])) / 3;
    //cin.close();
    //cout.close();
    return 0;
}