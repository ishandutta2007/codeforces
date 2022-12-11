#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int MASK = 1024;
int cnt[MASK];

vector<pii> cs[MASK];
int main(){
    fastIO;
    int n;
    cin >> n;
    int q;
    cin >> q;
    int mask;
    int m;
    int b;
    for(int i = 0 ; i < n ; i ++ ){
        mask = 0;
        cin >> m;
        for(int j = 0 ; j < m ; j ++ ){
            cin >> b;
            -- b;
            mask |= (1 << b);
        }
        for(int t = 0 ; t < MASK; t ++ )
            if((t&mask) == mask)cnt[t] ++ ;
    }
    int cl;
    for(int i = 1; i <= q; i ++ ){
        cin >> cl >> m;
        mask = 0;
        for(int j = 0 ; j < m ; j ++ ){
            cin >> b;
            -- b;
            mask |= (1 << b);
        }
        cs[mask].push_back(mp(cl,i));
    }
    for(int i = 0 ; i < MASK; i ++ ){
        sort(cs[i].begin(), cs[i].end());
    }
    int i1=-1,i2=-1;
    int bcnt = 0;
    int cost = (int)2e9 + 9;
    for(int i = 0 ; i < MASK; i ++ ){
        if(cs[i].size() >= 2){
            if(cnt[i] > bcnt){
                bcnt = cnt[i];
                cost = cs[i][0].fi + cs[i][1].fi;
                i1 = cs[i][0].se;
                i2 = cs[i][1].se;
            }
            else if(cnt[i] == bcnt && cs[i][0].fi + cs[i][1].fi < cost){
                cost = cs[i][0].fi + cs[i][1].fi;
                i1 = cs[i][0].se;
                i2 = cs[i][1].se;
            }
        }
    }
    for(int i = 0 ; i < MASK; i ++ ){
        for(int j = i + 1 ; j < MASK; j ++ ){
            if(cs[i].size() > 0 && cs[j].size() > 0){
                if(cnt[(i|j)] > bcnt){
                    bcnt = cnt[(i|j)];
                    cost = cs[i][0].fi + cs[j][0].fi;
                    i1 = cs[i][0].se;
                    i2 = cs[j][0].se;
                }
                else if(cnt[(i|j)] == bcnt && cs[i][0].fi + cs[j][0].fi < cost){
                    cost = cs[i][0].fi + cs[j][0].fi;
                    i1 = cs[i][0].se;
                    i2 = cs[j][0].se;
                }
            }
        }
    }
    cout << i1 << " " << i2 << "\n";
    return 0;
}