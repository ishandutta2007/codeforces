#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define MAXN 30005

long long w, h, n, x, y;
set<long long > H, V;
multiset<long long > hh, ww;
char c;

int main(){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> w >> h >> n;
    V.insert(0);
    V.insert(w);
    H.insert(0);
    H.insert(h);
    hh.insert(h);
    ww.insert(w);
    while (n--) {
        cin >> c >> x;
        if (c == 'H') {
            auto it = H.upper_bound(x);
            auto itt = H.upper_bound(x);
            itt--;
            hh.erase(hh.find(*it - *itt));
            hh.insert(*it - x);
            hh.insert(x - *itt);
            H.insert(x);
        } else {
            auto it = V.upper_bound(x);
            auto itt = V.upper_bound(x);
            itt--;
            ww.erase(ww.find(*it - *itt));
            ww.insert(*it - x);
            ww.insert(x - *itt);
            V.insert(x);
        }
        auto it1 = hh.end();
        it1--;
        auto it2 = ww.end();
        it2--;
        cout << *(it1) * *(it2) << endl;
    }
}