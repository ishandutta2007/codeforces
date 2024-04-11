#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const int N = 1e5+20,mod = 1e9+7,inf = 2e9,sq = 400;
int a[N];
deque<int> b[sq];
int cnt[sq][N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        b[i/sq].pb(a[i]);
        cnt[i/sq][a[i]]++;
    }
    cin >> q;
    int lastans = 0;
    rep(j,0,q){
        int t,l,r;
        cin >> t >> l >> r; 
        l = ((l+lastans-1)%n)+1;
        r = ((r+lastans-1)%n)+1;
        if (l > r) swap(l,r);
        l--;
        if (t == 1){
            if (l/sq == (r-1)/sq){
                int L = l/sq*sq,p = l/sq,R = min(n,L+sq);
                rep(i,L,R){
                    a[i] = b[p].front();
                    b[p].pop_front();
                }
                rep(i,L,l) b[p].pb(a[i]);
                b[p].pb(a[r-1]);
                rep(i,l,r-1) b[p].pb(a[i]);
                rep(i,r,R) b[p].pb(a[i]);
                continue;
            }
            int p = l/sq,L = p*sq,R = L+sq;
            int p2 = (r-1)/sq,L2 = p2*sq,R2 = min(n,L2+sq);
            rep(i,L,R){
                a[i] = b[p].front();
                b[p].pop_front();
            }
            rep(i,L2,R2){
                a[i] = b[p2].front();
                b[p2].pop_front();
            }
            cnt[p][a[R-1]]--;
            cnt[p][a[r-1]]++;
            cnt[p2][a[r-1]]--;
            rep(i,L,l) b[p].pb(a[i]);
            b[p].pb(a[r-1]);
            rep(i,l,R-1) b[p].pb(a[i]);
            int x = a[R-1];
            rep(i,L2,r-1) b[p2].pb(a[i]);
            rep(i,r,R2) b[p2].pb(a[i]);
            L = R;
            while (L < L2){
                p++;
                cnt[p][x]++;
                b[p].push_front(x);
                x = b[p].back();
                cnt[p][x]--;
                b[p].pop_back();
                L += sq;
            }
            b[p2].push_front(x);
            cnt[p2][x]++;
        }
        else{
            int k;
            cin >> k;
            k = ((k+lastans-1)%n)+1;
            if (l/sq == (r-1)/sq){
                int p = l/sq;
                int ans = 0,i = p*sq;
                for (int u : b[p]){
                    if (i < l){
                        i++;
                        continue;
                    }
                    if (i >= r) break;
                    if (u == k) ans++;
                    i++;
                }
                cout << ans << endl;
                lastans = ans;
                continue;
            }
            int p = l/sq,i = p*sq-1,ans = 0,p2 = (r-1)/sq;
            for (int u : b[p]){
                i++;
                if (i < l) continue;
                if (u == k) ans++;
            }
            p++;
            while (p < p2){
                ans += cnt[p][k];
                p++;
            }
            i = p*sq-1;
            for (int u : b[p]){
                i++;
                if (i >= r) break;
                if (u == k) ans++;
            }
            cout << ans << endl;
            lastans = ans;
        }
    }
}