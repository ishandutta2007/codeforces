#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int t[c], kezd[c], veg[c];
bool sq(int a) {
    int gy=sqrt(a);
    return (gy*gy==a);
}
void solve(int x) {
    if (x==-1) return;
    for (int i=x; ; i++) {
        if (sq(i)) {
            int s=i-x;
            solve(s-1);
            for (int j=x; j>=s; j--) {
                cout << j << " ";
            }
            return;
        }
    }
}
int main()
{
    int w;
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        solve(n-1);
        cout << "\n";
    }
    return 0;
}