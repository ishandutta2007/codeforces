#include <bits/stdc++.h>
#define long long ll


using namespace std;



int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int x1, y1, x2, y2;
    ios::sync_with_stdio(false);
    cin >> x1 >> y1 >> x2 >> y2;
    cout << max(abs(x1 - x2), abs(y1 - y2));
    //cin.close();
    //cout.close();
    return 0;
}