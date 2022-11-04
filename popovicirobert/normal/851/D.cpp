#include <bits/stdc++.h>
#define ll long long


using namespace std;

const ll INF = (ll) (1LL << 62);

const int MAXN = (int) 5e5;
const int MAXVAL = (int) 1e6;

bool ciur[MAXVAL + 1];

int cnt[MAXVAL + 1];

ll sp[MAXVAL + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j, x, y;
    ios::sync_with_stdio(false);
    cin >> n >> x >> y;
    for(i = 1; i <= n; i++) {
        int val;
        cin >> val;
        cnt[val]++;
        sp[val] += val;
    }
    for(i = 1; i <= MAXVAL; i++) {
        cnt[i] += cnt[i - 1];
        sp[i] += sp[i - 1];
    }
    for(i = 2; i * i <= MAXVAL; i++)
        if(ciur[i] == 0)
            for(j = i * i; j <= MAXVAL; j += i)
                ciur[j] = 1;
    ll ans = (1LL << 62);
    for(i = 2; i <= MAXVAL; i++)
       if(ciur[i] == 0) {
            ll sum = 0;
            bool flag = 0;
            for(j = i; j <= MAXVAL && flag == 0; j += i) {
                int val = j - (x + y - 1) / y;
                if(val < j - i)
                    val = j - i;
                sum += 1LL * y * (1LL * (cnt[j] - cnt[val]) * j - (sp[j] - sp[val]));
                if(INF / y < 1LL * (cnt[j] - cnt[val]) * j - (sp[j] - sp[val]))
                    flag = 1;
                if(sum < 0)
                    flag = 1;
                sum += 1LL * (cnt[val] - cnt[j - i]) * x;
                if(sum < 0)
                    flag = 1;
            }
            int val = j - (x + y - 1) / y;
            if(val < j - i)
                val = j - i;
            if(val > MAXVAL)
                val = MAXVAL;
            sum += 1LL * y * ((cnt[MAXVAL] - cnt[val]) * j - (sp[MAXVAL] - sp[val]));
            if(sum < 0)
                flag = 1;
            sum += 1LL * (cnt[val] - cnt[j - i]) * x;
            if(sum < 0)
                flag = 1;
            if(flag == 0)
                ans = min(ans, sum);
       }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}