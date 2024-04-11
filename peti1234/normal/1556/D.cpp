#include <bits/stdc++.h>

using namespace std;
long long t[10005], s[10005], n, k;
long long d(int a, int b) {
    cout << "and " << a << " " << b << "\n";
    cout << "or " << a << " " << b;
    cout.flush() << endl;
    long long x, y;
    cin >> x >> y;
    return x+y;
}
int main()
{
    cin >> n >> k;
    s[1]=d(2, 3), s[2]=d(1, 3), s[3]=d(1, 2);
    for (int i=4; i<=n; i++) {
        s[i]=d(1, i);
    }
    long long p=(s[1]+s[2]+s[3])/2;
    for (int i=1; i<=n; i++) {
        if (i<=3) {
            t[i]=p-s[i];
        } else {
            t[i]=s[i]-t[1];
        }
    }
    sort(t+1, t+n+1);
    cout << "finish " << t[k] << "\n";
    return 0;
}