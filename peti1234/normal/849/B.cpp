#include <bits/stdc++.h>

using namespace std;
long long n;
long long t[1002];
vector<long long> p;
bool e(long long a, long long b, long long c) {
    return (t[b]-t[a])*(c-a)==(t[c]-t[a])*(b-a);
}
bool ph(long long a, long long b, long long c, long long d) {
    return (t[b]-t[a])*(d-c)==(t[d]-t[c])*(b-a);
}
bool jo(long long a, long long b) {
    p.clear();
    for (long long i=1; i<=n; i++) if (!e(a, b, i)) p.push_back(i);
    long long si=p.size();
    if (si==0) return 0;
    if (si==1) return 1;
    long long c=p[0], d=p[1];
    for (long long i=2; i<si; i++) if (!e(c, d, p[i])) return 0;
    return ph(a, b, c, d);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (long long i=1; i<=n; i++) cin >> t[i];
    if (n==1) cout << "No";
    else if (n==2) cout << "Yes";
    else {
        if (jo(1, 2) || jo(1, 3) || jo(2, 3)) cout << "Yes";
        else cout << "No";
    }
    return 0;
}
// minden long long