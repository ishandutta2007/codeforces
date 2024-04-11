#include <bits/stdc++.h>

using namespace std;
int n;
long long opt=10000000000;
long long s[3001];
long long t[3001];
long long minker(long long p)
{
    int x=0;
    for (int i=1; i<p; i++) {
        if (s[i]<s[p] && t[i]<t[x]) {
            x=i;
        }
    }
    return x;
}
long long maxker(long long p)
{
    int x=0;
    for (int i=p+1; i<=n; i++) {
        if (s[i]>s[p] && t[i]<t[x]) {
            x=i;
        }
    }
    return x;
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> s[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    t[0]=INT_MAX;
    for (int i=2; i<n; i++) {
        long long p=t[i];
        long long a=minker(i);
        long long b=maxker(i);
        if (a!=0 && b!=0) {
            opt=min(opt, p+t[a]+t[b]);
        }
    }
    if (opt==10000000000) {
        opt=-1;
    }
    cout << opt << endl;
    return 0;
}