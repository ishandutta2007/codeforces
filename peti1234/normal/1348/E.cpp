#include <bits/stdc++.h>

using namespace std;
long long n, t, ps, ks, p[502], k[502], db;
bool v[502];
vector<long long> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> t;
    for (long long i=1; i<=n; i++) {
        cin >> p[i] >> k[i];
        ps+=p[i], ks+=k[i];
    }
    db=ps/t+ks/t, ps%=t, ks%=t;
    v[0]=true;
    for (long long i=1; i<=n; i++) {
        sz.clear();
        for (long long j=0; j<t; j++) if (v[j]) sz.push_back(j);
        for (long long j=0; j<sz.size(); j++) {
            long long x=sz[j];
            for (long long f=1; f<t; f++) {
                if (p[i]>=f && k[i]>=t-f) v[(x+f)%t]=1;
            }
        }
    }
    for (long long i=1; i<t; i++) {
        if (ps>=i && ks>=t-i && v[i]) ps=0, ks=0, db++;
    }
    cout << db << endl;
    return 0;
}
// minden ll