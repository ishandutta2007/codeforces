#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 100;

ll q[maxn], sz, cnt;

bool check(ll x){
    ll sum = 0;
    while (x > 0){
        ll l = 1, r = maxn;
        while (r - l > 1){
            ll m = (l + r) / 2;
            if (m * m * m <= x)
                l = m;
            else
                r = m;
        }
        if (q[l] != x / (l * l * l))
            return 0;
        sum += q[l];
        x %= l * l * l;
    }
    return sum == cnt;
}

int main(){
    ll m;
    cin >> m;
    ll sum = 0;
    for (ll i = 1; i < maxn; i++){
        ll nxt = i + 1;
        nxt = nxt * nxt * nxt;
        q[i] = (nxt - 1 - sum) / (i * i * i);
        if (sum + q[i] * i * i * i > m){
            while (sum + q[i] * i * i * i > m)
                q[i]--;
            sum += q[i] * i * i * i;
            cnt += q[i];
            break;
        }
        sum += q[i] * i * i * i;
        sz++;
        cnt += q[i];
    }
    cout << cnt << ' ';
    for (ll i = sz; i > 0; i--)
        while (q[i] > 0){
            ll x = i + 1;
            ll now = i;
            bool first = 0;
            while (now < maxn - 1){
                x = now + 1;
                q[now]--;
                q[x]++;
                if (sum + x * x * x - now * now * now > m || !check(sum + x * x * x - now * now * now)){
                    q[x]--;
                    q[now]++;
                    if (now == i)
                        first = 1;
                    break;
                }
                sum += x * x * x - now * now * now;
                now++;
            }
            if (first)
                break;
        }
    cout << sum;
}
//409477218238718 - 16542386125