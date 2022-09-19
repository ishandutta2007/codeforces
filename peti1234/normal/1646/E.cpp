#include <bits/stdc++.h>

using namespace std;
const int c=72000005;
int db[22];
bool s[c];
long long n, m, po[1000005], ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=20; i++) {
        for (int j=1; j<=m; j++) {
            if (!s[i*j]) {
                s[i*j]=1;
                db[i]++;
            }
        }
        db[i]+=db[i-1];
    }
    for (long long i=2; i<=n; i++) {
        long long db=0;
        for (long long j=1; j<=n; j*=i) {
            po[j]=max(po[j], db);
            db++;
        }
    }
    ans=1;
    for (int i=2; i<=n; i++) {
        if (po[i]>1) continue;
        long long ert=1, cnt=0;
        while (ert*i<=n) {
            ert*=i;
            cnt++;
        }
        ans+=db[cnt];
    }
    cout << ans << "\n";
    return 0;
}
/*
1000000 1000000
*/