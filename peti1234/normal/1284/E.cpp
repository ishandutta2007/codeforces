#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int c=2502;
ll n, ans, x[c], y[c], db, a, ps, ns, l, p, cnt;
vector<int> poz, neg;
bool f(int b, int c) {return (x[b]-x[a])*(y[c]-y[a])>(x[c]-x[a])*(y[b]-y[a]);}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> x[i] >> y[i];
    for (int i=1; i<=n; i++) {
        poz.clear(), neg.clear(), db=(n-1)*(n-2)*(n-3)/6, a=i;
        for (int j=1; j<=n; j++) {
            if (j!=i) {
                if (x[j]>=x[i]) poz.push_back(j);
                else neg.push_back(j);
            }
        }
        ps=poz.size(), ns=neg.size(), p=0, cnt=ps;
        sort(poz.begin(), poz.end(), f);
        sort(neg.begin(), neg.end(), f);
        for (int i=0; i<ps; i++) {
            while(p<ns && f(poz[i], neg[p])) p++, cnt++;
            cnt--, db-=(cnt-1)*cnt/2;
        }
        p=0, cnt=ns;
        for (int i=0; i<ns; i++) {
            while(p<ps && f(neg[i], poz[p])) p++, cnt++;
            cnt--, db-=(cnt-1)*cnt/2;
        }
        ans+=db;
    }
    cout << ans*(n-4)/2;
    return 0;
}
/*
6
2 0
-2 0
1 1
1 -1
-1 1
-1 -1
*/