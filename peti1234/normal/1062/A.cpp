#include <bits/stdc++.h>

using namespace std;
int t[102];
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    t[n+1]=1001;
    int m=0;
    int s=0;
    for (int i=1; i<=n+1; i++) {
        if (t[i]==t[i-1]+1) {
            s++;
            m=max(m, s);
        } else {
            s=0;
        }
    }
    cout << max(0, m-1) << endl;
    return 0;
}