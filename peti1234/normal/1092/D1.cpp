#include <bits/stdc++.h>

using namespace std;
int n, dif, x;
int main()
{
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x;
        dif+=x%2*(1-i%2*2);
    }
    cout << (dif==0 || dif==1 && n%2 ? "YES" : "NO");
    return 0;
}