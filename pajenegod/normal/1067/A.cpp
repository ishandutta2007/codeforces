#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

int main() {
	ll mod = 998244353;
    
    cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vi A(n);
    for (int i=0;i<n;++i)
    {
        cin >> A[i];
        A[i] -= 1;
    }

    vi ways_g(200);
    vi ways_s(200);

    if (A[0]<0)
    {
        for (int i=0; i<200; ++i)
        {
            ways_s[i]=1;
        }
    }
    else
    {
        ways_s[A[0]] = 1;
    }


    for (int i=1; i<n; ++i)
    {
        ll a = A[i];
        
        vi new_ways_g(200);
        vi new_ways_s(200);

        ll total = 0;
        for (int j=199; j>=0; --j)
        {
            total += ways_g[j];
            while (total>=mod)
                total-=mod;
            new_ways_g[j] = total + ways_s[j];
        }

        total = 0;
        for (int j=0; j<200; ++j)
        {
            new_ways_s[j] = total;

            total += ways_s[j] + ways_g[j];
            while (total>=mod)
                total-=mod;
        }

        if (a>=0)
        {
            for (int j=0;j<200;++j)
            {
                ways_s[j] = (j==a) ? new_ways_s[j] : 0;
                ways_g[j] = (j==a) ? new_ways_g[j] : 0;
            }
        } else {
            ways_g = new_ways_g;
            ways_s = new_ways_s;
        }
    }
    


    ll sum = 0;
    for (auto a : ways_g)
    {
        sum += a;
        while (sum>=mod)
            sum -= mod;
    }
    cout << sum;
}