#include <bits/stdc++.h>

using namespace std;
long long n, m, db, w, q=1;
vector<long long> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m, db=(q<<m), sz.clear();
        for (int i=1; i<=n; i++) {
            string s; cin >> s;
            long long sum=0;
            for (int i=0; i<m; i++) if (s[i]=='1') sum+=q<<(m-1-i);
            sz.push_back(sum);
        }
        for (long long i=db/2-105; i<=db/2+105; i++) {
            long long x=i, l=x, h=db-1-x;
            for (int i=0; i<n; i++) {
                if (sz[i]<x) l--;
                if (sz[i]>x) h--;
                if (sz[i]==x) l-=1000;
            }
            if (h==l || l+1==h) {
                string s;
                for (int i=0; i<m; i++) {
                    if (x%2) s+='1';
                    else s+='0';
                    x/=2;
                }
                reverse(s.begin(), s.end());
                cout << s << "\n";
            }
        }
    }
    return 0;
}