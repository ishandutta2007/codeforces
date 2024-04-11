#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)2e5 + 10;
const int M = 60;
const int K = 15;
bitset<M> like[N];
int dp[1 << K];

int main(){
    fastIO;
    int n, m, p;
    cin >> n >> m >> p;
    char f;
    for(int i = 0; i < n; i ++ ){
        for(int j = 0 ; j < m ; j ++ ){
            cin >> f;
            if(f == '1'){
                like[i][j] = 1;
            }
        }
    }
    vector<int> outp(m);
    int res = -1;
    int id;
    int pp;
    int mask;
    int sol;
    for(int cand = 0; cand < 20; cand ++ ){
        vector<int> qq;
        id = ((int)rng() % n + n) % n;
        for(int i = 0 ; i < m ; i ++ ){
            if(like[id][i])qq.push_back(i);
        }
        pp = qq.size();
        for(int i = 0 ; i < (1 << pp); i ++ ){
            dp[i] = 0;
        }
        for(int i = 0 ; i < n; i ++ ){
            mask = 0;
            for(int j = 0 ; j < qq.size(); j ++ ){
                if(like[i][qq[j]]){
                    mask |= (1 << j);
                }
            }
            dp[mask] ++ ;
        }
        for(int lg = 0 ;lg < pp; lg ++ ){
            for(int i = 0 ; i < (1 << pp); i ++ ){
                if((i & (1 << lg))){
                    dp[(i ^ (1 << lg))] += dp[i];
                }
            }
        }
        for(int i = 0 ; i < (1 << pp); i ++ ){
            if(dp[i] >= (n + 1) / 2){
                sol = __builtin_popcount(i);
                if(sol > res){
                    res = sol;
                    for(int j = 0 ; j < m ; j ++ ){
                        outp[j] = 0;
                    }
                    for(int j = 0 ; j < pp; j ++ ){
                        if((i & (1 << j))){
                            outp[qq[j]] = 1;
                        }
                    }
                }
            }
        }
    }
    for(auto x : outp)
        cout << x;
    cout << "\n";
    return 0;
}