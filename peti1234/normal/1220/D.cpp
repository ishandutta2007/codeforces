#include <bits/stdc++.h>

using namespace std;
vector<long long> v[66], sol;
long long n, m, ln;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (long long i=1; i<=n; i++) {
        long long x;
        cin >> x;
        long long y=x, a=0;
        while(!(x%2)) {
            x/=2;
            a++;
        }
        v[a].push_back(y);
        if (v[a].size()>ln) {
            m=a;
            ln++;
        }
    }
    for (long long i=0; i<65; i++) {
        if (i!=m) {
            for (long long j=0; j<v[i].size(); j++) {
                sol.push_back(v[i][j]);
            }
        }
    }
    cout << sol.size() << "\n";
    for (long long i=0; i<sol.size(); i++) {
        cout << sol[i] << " ";
    }
    return 0;
}