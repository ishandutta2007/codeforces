#include<iostream>
using namespace std;

const int N = 10 + 5;

int xr[N], yr[N], xb[N], yb[N];

int main() {
    int r, b;
    cin >> r >> b;
    for(int i = 0; i < r; i++) cin >> xr[i] >> yr[i];
    for(int i = 0; i < b; i++) cin >> xb[i] >> yb[i];

    if(r == b) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}