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

long long n, x, w;
pair<long long, long long> p[200005];

int main(){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n) {
        cin >> x >> w;
        p[i] = {x + w, x - w};
    }
    sort(p, p + n);
    int ans = 0;
    long long cur = - (1ll << 55);
    REP (i, n) if (p[i].second >= cur){
        cur = p[i].first;
        ans++;
    }
    cout << ans;
}