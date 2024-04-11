#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 6

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, m, i;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    if(n < 30) {
        int p2 = 1;
        for(i = 0; i < n; i++)
           p2 *= 2;
        cout << m % p2;
    }
    else
        cout << m;
    //cin.close();
    //cout.close();
    return 0;
}