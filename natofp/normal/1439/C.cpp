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
const int roz = (1 << 19);
 
ll sum[roz];
int mini[roz];
int lazy[roz];
bool marked[roz];
int sz[roz];
 
void push(int v){
    if(marked[v]){
        for(int i=v*2;i<=v*2+1;i++){
            lazy[i] = lazy[v];
            mini[i] = lazy[v];
            sum[i] = (ll)lazy[v] * sz[i];
            marked[i] = true;
        }
        marked[v] = false;
        lazy[v] = 0;
    }
}
 
void add(int lo, int hi, int u, int a, int b, int v){
    if(lo == a && b == hi){
        sum[u] = (ll)v * (hi - lo);
        mini[u] = v;
        lazy[u] = v;
        marked[u] = true;
        return;
    }
    if(b <= a) return;
    push(u);
    int mid = (lo + hi) / 2;
    add(lo, mid, u * 2, a, min(b, mid), v);
    add(mid, hi, u * 2 + 1, max(a, mid), b, v);
    sum[u] = sum[u * 2] + sum[u * 2 + 1];
    mini[u] = min(mini[u * 2], mini[u * 2 + 1]);
    return;
}
 
ll ask(int lo, int hi, int u, int a, int b){
    if(lo == a && b == hi){
        return sum[u];
    }
    if(b <= a) return 0LL;
    push(u);
    int mid = (lo + hi) / 2;
    ll L = ask(lo, mid, u * 2, a, min(b, mid));
    ll R = ask(mid, hi, u * 2 + 1, max(a, mid), b);
    return L + R;
}
 
void ini(){
    for(int i=roz/2;i<roz;i++) sz[i] = 1;
    for(int i=roz/2-1;i>=1;i--) sz[i] = sz[i * 2] + sz[i * 2 + 1];
}
 
int fiSEQ(int value){
    int pos = 1;
    while(pos < roz / 2){
        push(pos);
        if(mini[pos * 2] <= value || mini[pos * 2 + 1] > value) pos *= 2;
        else{
            pos *= 2; pos += 1;
        }
    }
    return pos - roz / 2;
}
 
int a[nax];
int n, q;
 
ll all;
 
int fiPrefBigger(ll value){
    if(all <= value) return -1;
    int pos = 1;
    ll bal = 0;
    while(pos < roz / 2){
        push(pos);
        if(bal + sum[pos * 2] <= value){
            bal += sum[pos * 2];
            pos *= 2; pos += 1;
        }
        else pos *= 2;
    }
    return pos - roz / 2;
}
 
 
 
 
 
void solve(){
    ini();
    cin >> n >> q;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<roz/2;i++) add(0,roz/2,1,i,i+1,0);
    for(int i=0;i<n;i++) add(0,roz/2,1,i,i+1,a[i]);
    all = ask(0, roz / 2, 1, 0, n);
    while(q--){
        int tp, x, y; cin >> tp >> x >> y;
        x--;
        if(tp == 1){
            int lo = fiSEQ(y);
            int hi = x;
            add(0,roz/2,1,lo,hi+1,y);
            all = ask(0, roz / 2, 1, 0, n);
        }
        else{
            x--; // -1 ?
            int ans = 0;
            ll bal = y;
            int pos = x;
            while(pos < n){
                ll cur = ask(0, roz / 2, 1, 0, pos + 1);
                int go = fiPrefBigger(cur + bal);
                if(go == -1){
                    ans += (n - pos - 1);
                    break;
                }
                else{
                    ans += (go - pos - 1);
                    ll cost = ask(0, roz / 2, 1, pos + 1, go);
                    bal -= cost;
                    pos = fiSEQ(bal);
                    pos--;
                }
            }
            cout << ans << "\n";
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while(tt--) solve();
 
    return 0;
}