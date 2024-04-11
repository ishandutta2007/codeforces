#include <bits/stdc++.h>

using namespace std;

long long n, t[1005], po[22], k, ert, ans;
set<long long> s;
int main()
{
    ios_base::sync_with_stdio(false);
    po[0]=1;
    for (int i=1; i<=20; i++) po[i]=po[i-1]*3;
    cin >> n >> k;
    ert=po[k]-1;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<k; j++) {
            long long x;
            cin >> x;
            t[i]+=x*po[j];
        }
        s.insert(t[i]);
        //cout << "fontos " << i << " "  << t[i] << "\n";
    }
    for (int i=1; i<=n; i++) {
        int db=0;
        for (int j=1; j<=n; j++) {
            if (j!=i) {
                long long cel=0, a=t[i], b=t[j];
                for (int s=0; s<k; s++) {
                    cel+=po[s]*((6-(a%3+b%3))%3);
                    a/=3, b/=3;
                }
                if (s.count(cel)) {
                    db++;
                }
            }
        }
        db/=2;
        //cout << "vege " << i << " " << db << "\n";
        ans+=db*(db-1)/2;
    }
    cout << ans << "\n";
    return 0;
}
/*
1
1
a
*/