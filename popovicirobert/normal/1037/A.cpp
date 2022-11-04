#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    int bit = 0;
    while((1 << bit) <= n) {
        bit++;
    }
    cout << bit;
    //cin.close();
    //cout.close();
    return 0;
}