#include <bits/stdc++.h>

using namespace std;
const long long c=200002;
long long ans=1, n, db[c];
bool hat[c];
vector<long long> oszt[c];
int main()
{
    ios_base::sync_with_stdio(false);
    for (long long i=2; i<c; i++) {
        if (oszt[i].size()==0) {
            long long p=i;
            while(p<c) hat[p]=1, p*=i;
        }
        for (long long j=i; j<c; j+=i) oszt[j].push_back(i);
    }
    cin >> n;
    for (long long i=1; i<=n; i++) {
        long long x;
        cin >> x;
        for (long long i=0; i<oszt[x].size(); i++) db[oszt[x][i]]++;
    }
    for (long long i=c-2; i>=1; i--) {
        if (hat[i] && db[i]>=n-1) {
            ans*=i;
            for (long long j=0; j<oszt[i].size(); j++) db[oszt[i][j]]=0;
        }
    }
    cout << ans << endl;
    return 0;
}