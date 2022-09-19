#include <bits/stdc++.h>

using namespace std;
int n;
long long a[100001];
long long b[100001];
long long s;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i] >> b[i];
    }
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    s=n;
    for (int i=1; i<=n; i++) {
        s+=max(a[i], b[i]);
    }
    cout << s << endl;
    return 0;
}