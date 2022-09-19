#include <bits/stdc++.h>

using namespace std;
int n, s;
int t[200001];
long long p=0;
int main()
{
    cin >> n >> s;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    for (int i=1; i<=n/2; i++) {
        p+=max(0, t[i]-s);
    }
    p+=abs(t[(n+1)/2]-s);
    for (int i=(n+3)/2; i<=n; i++) {
        p+=max(0, s-t[i]);
    }
    cout << p << endl;
    return 0;
}