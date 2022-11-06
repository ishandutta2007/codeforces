#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f0rn(i, a, b) for (int i=a; i<(b); i++)
#define forn(i,n) for(int i = 0; i < n; i++)
const int MAXN = 500005;
 
int n, d;
ll k;
ll arr[MAXN];
 
ll test(ll k, int d, ll end) {
    ll addsum = 0LL;
    queue<ll> q;
    ll res = 0;
    forn(l,n) {
        if(!q.empty() && l-d-1 == q.front()) {
            q.pop();
            addsum -= q.front();
            q.pop();
        }
        ll sum = arr[min(n-1,l+d)] - (l <= d ? 0 : arr[l-d-1]);
        if(sum + addsum < k) {
            q.push((ll) (l+d));
            q.push(k-sum-addsum);
            res += k-sum-addsum;
            addsum = k-sum;
        }
        if(res>end) return res;
    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> d >> k;
    forn(i, n) {
        cin >> arr[i];
    }
    f0rn(i, 1, n) {
        arr[i] += arr[i-1];
    }
    ll l = 0, r = 2000000000000000000LL;
    while(l < r) {
        ll m = (l+r)>>1;
        if(test(m,d,k) <= k) l=m+1;
        else r=m;
    }
    cout << l-1;
}