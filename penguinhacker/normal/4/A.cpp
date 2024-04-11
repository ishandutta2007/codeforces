#include <bits/stdc++.h>
using namespace std;

int w;
int main() {
    cin >> w;
    if (w < 4) cout << "NO";
    else if (w%2 == 0) cout << "YES";
    else cout << "NO";
    return 0;
}