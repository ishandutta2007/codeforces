#include <bits/stdc++.h>
#define ll long long


using namespace std;

const int MAXN = (int) 1e5;

struct Data {
    int s, a, b;
    bool operator <(const Data &other) const {
        return a - b > other.a - other.b;
    }
}v[MAXN + 1];

int n;
ll nr = 0, sum = 0;
int s;

inline ll solve(ll nr1, ll nr2) {
    int i;

    nr1 = 1LL * ((nr1 + s - 1) / s) * s;
    nr2 = 1LL * ((nr2 + s - 1) / s) * s;

    ll cnt = 0;
    ll ans = 0;

    for(i = 1; i <= n; i++) {

       // if(v[i].a != v[i].b) {
            ans += 1LL * v[i].s * v[i].b;

            if(v[i].a > v[i].b) {
                ans += 1LL * min((ll) v[i].s, nr1 - cnt) * (v[i].a - v[i].b);
                cnt += min((ll) v[i].s, nr1 - cnt);
            }
            else if(sum - nr2 - cnt > 0) {
                ans += 1LL * min((ll) v[i].s, sum - nr2 - cnt) * (v[i].a - v[i].b);
                cnt += min((ll) v[i].s, sum - nr2 - cnt);
            }

       // }
    }

    return ans;
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> n >> s;

    ll nr1 = 0, nr2 = 0;
    //ll bonus = 0;

    for(i = 1; i <= n; i++) {
        cin >> v[i].s >> v[i].a >> v[i].b;

      //  if(v[i].a != v[i].b) {
            sum += v[i].s;

            if(v[i].a > v[i].b)
                nr1 += v[i].s;
            else
                nr2 += v[i].s;

      //  }
      //  else
      //      bonus += 1LL * v[i].s * v[i].a;

    }

    nr = 1LL * ((sum + s - 1) / s) * s;

    sort(v + 1, v + n + 1);

    ll ans = 0;
    if((nr + s - 1) / s == (nr1 + s - 1) / s + (nr2 + s - 1) / s)
        ans = solve(nr1, nr2);
    else {
        ll r1, r2;
        if(nr1 % s == 0)
            r1 = s;
        else
            r1 = nr1 % s;
        if(nr2 % s == 0)
            r2 = s;
        else
            r2 = nr2 % s;
        ans = max(solve(nr1 - r1, nr2 + r1), solve(nr1 + r2, nr2 - r2));
    }

    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}