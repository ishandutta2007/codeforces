#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 3010;

vector<ll> P[N];
int k;

ll outp = 0ll;

void solve(int li, int ri, vector<ll> dp){ // d&c-ish
    if(li == ri){
        int sz = P[li].size() - 1;
        int iq;
        for(int i = 0 ; i <= k ; i ++ ){
            outp = max(outp, dp[i] + P[li][min(k - i, sz)]);
        }
        return ;
    }
    int mid = (li + ri) / 2;
    vector<ll> lef = dp, rig = dp;
    int sz;
    for(int i = li ; i <= mid ; i ++ ){
        sz = (int)P[i].size() - 1;
        for(int j = k ; j >= 0 ; j -- ){
            if(j + sz <= k){
                lef[j + sz] = max(lef[j + sz], lef[j] + P[i].back());
            }
        }
    }
    for(int i = mid + 1; i <= ri ;i ++ ){
        sz = P[i].size() - 1;
        for(int j = k ; j >= 0 ; j -- ){
            if(j + sz <= k){
                rig[j + sz] = max(rig[j + sz], rig[j] + P[i].back());
            }
        }
    }
    solve(li, mid, rig);
    solve(mid + 1, ri, lef);
}

int main(){
    fastIO;
    int n;
    cin >> n >> k;
    int t;
    ll x;
    for(int i = 1; i <= n; i ++ ){
        cin >> t;
        P[i].push_back(0ll);
        for(int j = 1; j <= t; j ++ ){
            cin >> x;
            P[i].push_back(P[i].back() + x);
        }
    }
    vector<ll> emp(k + 1);
    solve(1, n, emp);
    cout << outp << "\n";
    return 0;
}