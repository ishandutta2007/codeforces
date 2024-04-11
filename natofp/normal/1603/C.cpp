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

const int mod = 998244353;
const int nax = 1e5 + 5;
int a[nax];
int c[nax];
int n;

void xd(){
    for(int v1=1;v1<=50;v1++){
        for(int v2=1;v2<=50;v2++){
            int c = (v1 + v2 - 1) / v2;
            bool ok = ((v1 + c - 1) / c <= v2);
            if(ok && c > 1){
                c -= 1;
                if(((v1 + c - 1) / c <= v2)) ok = false;
            }
            assert(ok);
        }
    }
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) c[i] = 1;
    ll ans = 0;
    ll curSum = 0;
    for(int i=2;i<=n;i++){
        int ptr = i - 1;

        while(ptr >= 1 && (a[ptr] + c[ptr] - 1) / c[ptr] > a[ptr + 1] / c[ptr + 1]){
            int curC = c[ptr];
            int bound = (a[ptr + 1] / c[ptr + 1]);

            int val = a[ptr];
            // sufit val / c <= bound (MINIMALNE C TAKIE !)
            int need = (a[ptr] + bound - 1) / bound;
            //while((val + need - 1) / need > bound) need += 1;

            curSum += ((ll)need - curC) * ptr;
            curSum %= mod;
            c[ptr] = need;
            ptr -= 1;
        }
        ans += curSum;
        ans %= mod;
        //cout << i << " " << curSum << endl;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt; cin >> tt;
    while(tt--) solve();


    return 0;
}