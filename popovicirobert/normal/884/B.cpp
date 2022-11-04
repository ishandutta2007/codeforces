#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & (-x))


using namespace std;



int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x, a;
    ios::sync_with_stdio(false);
    cin >> n >> x;
    int s = 0;
    for(i = 1; i <= n; i++) {
        cin >> a;
        s += a;
    }
    if(s + n - 1 == x)
        cout << "YES";
    else
        cout << "NO";
    //cin.close();
    //cout.close();
    return 0;
}