#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
ll Q[N];
ll A[N];

struct Node{
    pii low;
    pii high;
};

Node T[N * 4 + 512];

void build(int node, int cl, int cr){
    if(cl == cr){
        T[node].low = T[node].high = mp(Q[cl], cl);
        return;
    }
    int mid = (cl + cr) / 2;
    build(node * 2, cl, mid);
    build(node * 2 + 1, mid + 1, cr);
    T[node].low = min(T[node * 2].low, T[node * 2 + 1].low);
    T[node].high = max(T[node * 2].high, T[node * 2 + 1].high);
}

Node get(int node, int cl, int cr, int tl, int tr){
    if(cr < tl || cl > tr) return {mp((ll)1e18, -1ll), mp(-(ll)1e18, -1ll)};
    if(cl >= tl && cr <= tr){
        return T[node];
    }
    int mid = (cl + cr) / 2;
    Node ga = get(node * 2, cl, mid, tl, tr);
    Node gb = get(node * 2 + 1, mid + 1, cr, tl, tr);
    return {min(ga.low, gb.low), max(ga.high, gb.high)};
}

ll pre[N];
ll suf[N];

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 0 ; i <= n + 1; i ++ ){
        A[i]=0ll;
        Q[i]=0ll;
        pre[i]=0ll;
        suf[i]=0ll;
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        Q[i] = A[i] + Q[i - 1];
        pre[i]=min(A[i],pre[i-1]+A[i]);
    }
    for(int i = n; i >= 1; i -- ){
        suf[i]=min(A[i],suf[i+1]+A[i]);
    }
    Q[n + 1] = Q[n];
    build(1, 0, n + 1);
    int li,ri;
    li = ri = k;
    int chk;
    int cl, cr;
    int jump;
    Node qr;
    ll cum = A[k];
    ll v1, v2;
    int ii, jj;
    while(1){
        if(li == 1 || ri == n){
            cout << "YES\n";
            return;
        }
        if(cum + pre[li - 1] >= 0 || cum + suf[ri + 1] >= 0){
            cout << "YES\n";
            return;
        }
        cl = li;
        v1 = v2 = -(ll)1e18;
        ii = jj = -1;
        for(int lg = 18 ; lg >= 0 ;lg -- ){
            if(cl - (1 << lg) >= 1){
                jump = cl - (1 << lg);
                qr = get(1, 0, n + 1, jump - 1, li - 2);
                if(cum + Q[li - 1] - qr.high.fi >= 0){
                    cl = jump;
                    v1 = cum + Q[li - 1] - qr.low.fi;
                    ii = qr.low.se + 1;
                }
            }
        }
        cr = ri;
        for(int lg = 18; lg >= 0 ; lg -- ){
            if(cr + (1 << lg) <= n){
                jump = cr + (1 << lg);
                qr = get(1, 0, n + 1, ri + 1, jump);
                if(cum + qr.low.fi - Q[ri] >= 0){
                    cr = jump;
                    v2 = cum + qr.high.fi - Q[ri];
                    jj = qr.high.se;
                }
            }
        }
        if(ii == -1 && jj == -1){
            cout << "NO\n";
            return;
        }
        if(v1 >= v2 && cum + v1 >= 0){
            li = ii;
            cum = v1;
        }
        else{
            ri = jj;
            cum = v2;
        }
    }
    cout << "NO\n";
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}