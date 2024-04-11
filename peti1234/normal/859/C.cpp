#include <bits/stdc++.h>

using namespace std;
int n;
int t[51];
int d[52];
int s;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        s+=t[i];
    }
    for (int i=n; i>=1; i--) {
        d[i]=max(t[i]-d[i+1], d[i+1]-t[i]);
    }
    //cout << d[1] << endl;
    s-=d[1];
    cout << s/2 << " " << s/2+d[1] << endl;
    return 0;
}