#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, m, kezd[c], veg[c], pos, maxi;
string x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    cin >> x >> y;
    for (int i=0; i<n; i++) {
        if (x[i]==y[pos]) {
            kezd[pos]=i;
            pos++;
        }
    }
    pos=m-1;
    for (int i=n-1; i>=0; i--) {
        if (x[i]==y[pos]) {
            veg[pos]=i;
            pos--;
        }
    }
    for (int i=0; i<m-1; i++) {
        maxi=max(maxi, veg[i+1]-kezd[i]);
    }
    cout << maxi << "\n";
    return 0;
}