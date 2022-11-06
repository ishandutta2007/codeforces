#include <bits/stdc++.h>
using namespace std;
 
int X, Y;
 
int main() {
    cin >> X >> Y;
    if (Y == 0) return cout << "No\n", 0;
    if (Y == 1 && X) return cout << "No\n", 0;
    int P = (Y - 1);
    if (P > X || ((X - P) & 1)) cout << "No\n";
    else cout << "Yes\n";
}