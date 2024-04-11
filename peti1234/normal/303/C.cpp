#include <bits/stdc++.h>

using namespace std;
const int c=1000002;
int n, k, t[5002], cnt[c], a[c], db, sum;
bool v[5002];
vector<pair<int, int> > sz[c], h;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> t[i];
    for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++) cnt[abs(t[i]-t[j])]++;
    for (int i=n-k; i<c; i++) {
        h.clear(), db=0, sum=0;
        for (int j=i; j<c; j+=i) db+=cnt[j];
        if (db>k*(k+1)/2) continue;
        for (int j=1; j<=n; j++) {
            sum+=(a[t[j]%i]==i);
            a[t[j]%i]=i;
        }
        if (sum<=k) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}
/*
7 1
0 2 3 4 5 6 7
*/