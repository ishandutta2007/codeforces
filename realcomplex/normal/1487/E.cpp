#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 150010;
int n[4];
vector<int> q[4];
set<int> pv[4][N];
vector<pii> dp[4];

int main(){
    fastIO;
    for(int i = 0; i < 4; i ++ )
        cin >> n[i];
    for(int j = 0 ; j < 4; j ++) {
        q[j].resize(n[j]);
        for(int x = 0; x < n[j]; x ++ ){
            cin >> q[j][x];
        }
    }
    int xi, yi;
    int edg;
    for(int j = 1; j <= 3; j ++ ){
        cin >> edg;
        for(int id = 0; id < edg; id ++ ){
            cin >> xi >> yi;
            xi -- ;
            yi -- ;
            pv[j][yi].insert(xi);
        }
    }
    for(int j = 0 ; j < n[0]; j ++ ){
        dp[0].push_back(mp(q[0][j], j));
    }
    sort(dp[0].begin(), dp[0].end());
    int pp = 0;
    int cur;
    for(int i = 1; i < 4; i ++ ){
        for(int j = 0 ;j < q[i].size(); j ++ ){
            pp = 0;
            cur = (int)1e9;
            while(pp < dp[i-1].size()){
                if(!pv[i][j].count(dp[i-1][pp].se)){
                    if(dp[i-1][pp].fi < (int)1e9)
                        cur = dp[i-1][pp].fi + q[i][j];
                    break;
                }
                pp ++ ;
            }
            dp[i].push_back(mp(cur, j));
        }
        sort(dp[i].begin(), dp[i].end());
    }
    int outp = dp[3][0].fi;
    if(outp == (int)1e9){
        cout << "-1\n";
    }
    else{
        cout << outp << "\n";
    }
    return 0;
}