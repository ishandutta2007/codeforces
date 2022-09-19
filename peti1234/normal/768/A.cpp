#include <bits/stdc++.h>

using namespace std;
int n;
int t[100001];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    int k=0;
    for (int i=1; i<=n; i++) {
        if (t[i]>t[1] && t[i]<t[n]) k++;
    }
    cout << k << endl;
    return 0;
}