#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back

int main() {
    int asdf; cin >> asdf;
    while(asdf--) {
        int n, m; cin >> n >> m;
        vector<int> teach(n);
        F0R(i, n) cin >> teach[i];
        sort(teach.begin(), teach.end());
        reverse(teach.begin(), teach.end());
        teach.resize(m);
        reverse(teach.begin(), teach.end());

        
        vector<vector<int>> stud(m);
        vector<pii> sp(m);
        F0R(i, m) {
            int k; cin >> k;
            ll sum = 0;
            F0R(j, k) {
                int a; cin >> a;
                stud[i].pb(a);
                sum += a;
            }
            sum = (sum + k-1) / k;
            sp[i] = {(int) sum, i};
        }
        sort(sp.begin(), sp.end());

        int plus[m+1];
        int minus[m+1];
        int same[m+1];

        plus[0] = same[0] = 0;
        F0R(i, m) {
            same[i+1] = sp[i].f <= teach[i];
            plus[i+1] = i != m-1 && sp[i].f <= teach[i+1];
            minus[i+1] = i != 0 && sp[i].f <= teach[i-1];

            same[i+1] += same[i];
            plus[i+1] += plus[i];
            minus[i+1] += minus[i];
        }


        F0R(i, m) {
            ll sum = 0;
            int k = stud[i].size();
            F0R(j, k)
                sum += stud[i][j];

            int avg = (int) ((sum + k-1) / k);
            F0R(j, k) {
                int navg = (int) ((sum - stud[i][j] + k - 2) / (k - 1));
                int ins = lower_bound(sp.begin(), sp.end(), mp(navg, -1)) - sp.begin();
                int rem = lower_bound(sp.begin(), sp.end(), mp(avg, -1)) - sp.begin();
                
                if(rem >= ins) {
                    int sum = same[ins];
                    sum += (plus[rem] - plus[ins]);
                    sum += (same[m] - same[rem+1]);
                    sum += (teach[ins] >= navg);
                    cout << (sum == m);
                } else {
                    int sum = same[rem];
                    sum += (minus[ins] - minus[rem+1]);
                    sum += (same[m] - same[ins]);
                    sum += (teach[ins-1] >= navg);
                    cout << (sum == m);
                }
            }
        }
        cout << endl;
    }
}