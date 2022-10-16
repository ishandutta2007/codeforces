#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define st first
#define nd second
#define pii pair<long long,long long>
#define mp make_pair
#define pll pair<long long,long long>
#define int long long

using namespace std;

const int nax = 1e5 + 5;

int dp[nax];

const int roz = (1<<19);
int tree[roz];
void ustaw(int pos,int val)
{
    pos += roz/2;
    tree[pos] = val;
    pos /= 2;
    while(pos >= 1)
    {
        tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);
        pos >>= 1;
    }
    return;
}

int ask(int lo,int hi)
{
        lo += roz/2;
        hi += roz/2;
        if(lo > hi) return 1e9;
        int res = tree[lo];
        if(lo != hi) res = min(res, tree[hi]);
        while((lo>>1) != (hi>>1))
        {
            if((lo&1) == 0) res = min(res, tree[lo + 1]);
            if(hi&1) res = min(tree[hi - 1], res);
            lo >>= 1;
            hi >>= 1;
        }
        return res;
}

void solve(){
    int n; cin >> n;
    vector<pii> a;
    vector<int> wys;

    ll ans = 0;
    for(int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        a.pb(mp(x, y));
        ans += y;
        wys.pb(x);
    }
    sort(a.begin(), a.end());
    sort(wys.begin(), wys.end());
    for(int i=0;i<roz/2;i++) ustaw(i, 1e9);

    dp[n] = 1e9;
    stack<int> koksy;
    for(int i=n-1;i>=0;i--){
        dp[i] = 1e9;
        int lo = i;
        int mam = a[i].st + a[i].nd;
        int hi = n - 1;
        if(mam >= wys.back()){
            dp[i] = 0;
            ustaw(i, dp[i]);

            while(koksy.size()){
                int id = koksy.top();
                int was = a[id].st + a[id].nd;
                if(was <= mam){
                    koksy.pop();
                    continue;
                }
                else break;
            }
            koksy.push(i);
            continue;
        }
        else{
            auto it = upper_bound(wys.begin(), wys.end(), mam);
            it--;
            hi = (it - wys.begin());
        }
        //cout<<"WA"<<i<<" "<<lo<<" "<<hi<<endl;
        //bool dbg = (i == 0);
        dp[i] = ask(lo, hi);

        dp[i] = min(dp[i], max(0LL, - a[i].nd + (wys.back() - a[i].st)));

       // cout<<i<<" "<<dp[i]<<endl;
        while(koksy.size()){
                int id = koksy.top();
                int was = a[id].st + a[id].nd;
                if(was <= mam){
                    koksy.pop();
                    continue;
                }
                else break;
            }
        if(koksy.size()){
            int id = koksy.top();
            dp[i] = min(dp[i], dp[id] + max(0LL,  - a[i].nd + (wys[id] - a[i].st)));
            //if(dbg) cout<<"WAP"<<id<<endl;
        }
        koksy.push(i);
        //cout<<i<<" "<<dp[i]<<endl;
        ustaw(i, dp[i]);

    }



    cout << ans + dp[0] << "\n";





}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}