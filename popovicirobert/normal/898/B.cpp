#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, a, b;
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    int i = 0;
    while(i * a <= n) {
        if((n - i * a) % b == 0) {
            cout << "YES" << endl;
            cout << i << " " << (n - i * a) / b;
            return 0;
        }
        i++;
    }
    cout << "NO";
    //cin.close();
    //cout.close();
    return 0;
}