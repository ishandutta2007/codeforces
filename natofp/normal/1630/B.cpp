#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int nax = 2e5 + 5;
int a[nax];
int n;
int cnt[nax];
int pref[nax];
int k;

int ask(int lo, int hi){
    return pref[hi] - pref[lo - 1];
}

void solve(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        cnt[a[i]] += 1;
    }
    for(int i=1;i<=n;i++) pref[i] = pref[i - 1] + cnt[i];

    int ans = 2e9;
    int L = -1e9;
    int R = 1e9;
    int need = n;
    for(int i=n;i>=1;i--){
        int mam = i;
        int on = n - i;
        if(mam >= on + k) need = i;
    }
    for(int s=1;s<=n;s++){
        if(ask(s, n) < need) continue;
        int lo = s;
        int hi = n;
        while(lo + 1 < hi){
            int mid = (lo + hi) / 2;
            if(ask(s, mid) >= need) hi = mid;
            else lo = mid;
        }
        int odp = hi;
        if(ask(s, lo) >= need) odp = lo;
        int len = odp - s;
        if(len < ans){
            ans = len;
            L = s;
            R = odp;
        }
    }
    cout << L << " " << R << "\n";

    int done = 0;
    int bal = 0;
    int last = 0;
    for(int i=1;i<=n;i++){
        if(a[i] >= L && a[i] <= R) bal += 1;
        else bal -= 1;
        if(bal > 0 && done < k - 1){
            cout << last + 1 << " " << i << "\n";
            last = i;
            done += 1;
            bal = 0;
        }
    }
    cout << last + 1 << " " << n << "\n";

    for(int i=1;i<=n;i++) cnt[a[i]] -= 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}