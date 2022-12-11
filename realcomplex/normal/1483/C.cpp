#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 100;

struct segm{
    int hv;
    ll dp;
    ll val;
};

int h[N];
ll b[N];
ll dp[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> h[i];
    }
    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
    }
    segm cur;
    vector<segm> pq;
    for(int i = 1; i <= n; i ++ ){
        cur.hv = h[i];
        cur.dp = dp[i - 1];
        while(!pq.empty() && pq.back().hv > cur.hv){
            cur.dp = max(cur.dp, pq.back().dp);
            pq.pop_back();
        }
        cur.val = cur.dp + b[i];
        if(!pq.empty())
            cur.val = max(cur.val, pq.back().val);
        pq.push_back(cur);
        dp[i] = cur.val;
    }
    cout << dp[n] << "\n";
    return 0;
}