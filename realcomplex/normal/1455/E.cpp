#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int ab(int x){
    return max(x,-x);
}

int X[4], Y[4];
int per[4];

void solve(){
    vector<pii> pp(4);
    vector<int> wx, wy;
    for(int i = 0 ; i < 4; i ++ ){
        cin >> pp[i].fi >> pp[i].se;
        wx.push_back(pp[i].fi);
        wy.push_back(pp[i].se);
    }
    sort(wx.begin(), wx.end());
    sort(wy.begin(), wy.end());
    wx.resize(unique(wx.begin(), wx.end()) - wx.begin());
    wy.resize(unique(wy.begin(), wy.end()) - wy.begin());
    vector<int> cand = {};
    for(int i = 0 ; i < 4; i ++ ){
        for(int j = i + 1; j < 4; j ++ ){
            cand.push_back(ab(pp[j].fi-pp[i].fi));
            cand.push_back(ab(pp[j].se-pp[i].se));
        }
    }
    sort(cand.begin(), cand.end());
    cand.resize(unique(cand.begin(), cand.end()) - cand.begin());
    int dx = -1, dy = -1;
    ll soln = (ll)1e18;
    ll cur;
    for(int p = 0 ; p < 2; p ++ ){
        dy = -1;
        for(int q = 0; q < 2; q ++ ){
            for(auto len : cand){
                for(auto xx : wx){
                    for(auto yy : wy){
                        X[0] = xx;
                        Y[0] = yy;
                        X[1] = xx + dx * len;
                        Y[1] = yy;
                        X[2] = xx;
                        Y[2] = yy + dy * len;
                        X[3] = X[1];
                        Y[3] = Y[2];
                        for(int i = 0 ; i < 4; i ++ ) per[i]=i;
                        do{
                            cur = 0;
                            for(int i = 0 ; i < 4; i ++ ){
                                cur += ab(X[i]-pp[per[i]].fi);
                                cur += ab(Y[i]-pp[per[i]].se);
                            }
                            soln = min(soln,cur);
                        }while(next_permutation(per,per+4));
                    }
                }
            }
            dy *= -1;
        }
        dx *= -1;
    }
    cout << soln << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        solve();
    }
    return 0;
}