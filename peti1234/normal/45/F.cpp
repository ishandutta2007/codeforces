#include <bits/stdc++.h>

using namespace std;
int n, m;
int main()
{
    cin >> m >> n;
    if (n==1) {
        cout << -1;
        return 0;
    }
    if (n==2) {
        if (m==1) {
            cout << 1;
        }
        if (m==2) {
            cout << 5;
        }
        if (m==3) {
            cout << 11;
        }
        if (m>3) {
            cout << -1;
        }
    }
    if (n==3) {
        if (m<=3) {
            cout << 2*m-1;
        } else if (m<=5) {
            cout << 2*m+1;
        } else {
            cout << -1;
        }
    }
    if (n>3) {
        int ans=0;
        if (n<m) {
            m-=n-2;
            ans+=4;
        }
        while (n<m) {
            m-=n/2-1;
            ans+=2;
        }
        if (n>=2*m) {
            cout << ans+1;
        } else if (n>m) {
            cout << ans+3;
        } else if (n==m) {
            cout << ans+5;
        }
    }
    return 0;
}