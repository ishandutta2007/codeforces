#include <bits/stdc++.h>

using namespace std;
int n, x, y;
int t[101];
int p;
int main()
{
    cin >> n >> x >> y;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=(n+1)/2; i++) {
        int a=t[i];
        int b=t[n-i+1];
        if (a!=2 && b!=2 && a!=b) {
            cout << -1 << endl;
            return 0;
        }
        if (min(a, b)==2) {
            p+=min(x, y);
            if (i!=n-i+1) {
                p+=min(x, y);
            }
        }
        else if(max(a, b)==2) {
            if (min(a, b)==1) {
                p+=y;
            } else {
                p+=x;
            }
        }
    }
    cout << p << endl;
    return 0;
}