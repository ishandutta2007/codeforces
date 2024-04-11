#include <bits/stdc++.h>
#define lsb(x)
#define ll long long

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, a, b, c;
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    for(i = 1; i <= (int) 2e5; i++) {
        if((a * 10) / b == c) {
           cout << i;
           return 0;
        }
        a = (a * 10) % b;
    }
    cout << -1;
    //cin.close();
    //cout.close();
    return 0;
}