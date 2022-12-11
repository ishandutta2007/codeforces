#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 510;
int ins[N][N]; // i zeros j ones
int bits[N];

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> ids;
    for(int iq = 1; iq <= n; iq ++ ){
        ids.push_back(iq);
    }
    for(int i = 0 ; i <= n ;i ++ ){
        for(int j = 0 ; j <= n; j ++ ){
            ins[i][j]=-1;
        }
    }
    queue<pii> vis;
    vis.push(mp(n, 0));
    ins[n][0] = -1;
    int ii, jj;
    int t1;
    while(!vis.empty()){
        ii = vis.front().fi;
        jj = vis.front().se;
        vis.pop();
        for(int t0 = 0; t0 <= min(k, ii); t0 ++ ){
            t1 = k - t0;
            if(t1 <= jj){
                if(ins[ii + t1 - t0][jj + t0 - t1] == -1){
                    ins[ii + t1 - t0][jj + t0 - t1] = t0;
                    vis.push(mp(ii + t1 - t0, jj + t0 - t1));
                }
            }
        }
    }
    if(ins[0][n] == -1){
        cout << "-1" << endl;
        return 0;
    }
    vector<int> ord;
    pii cur = mp(0, n);
    int t0;
    while(cur != mp(n, 0)){
        t0 = ins[cur.fi][cur.se];
        t1 = k - t0;
        ord.push_back(t0);
        cur.fi = cur.fi + t0 - t1;
        cur.se = cur.se + t1 - t0;
    }
    reverse(ord.begin(), ord.end());
    int res = 0, xr;
    for(auto x : ord){
        t0 = x;
        t1 = k - x;

        cout << "? ";
        for(int j = 0 ; j < n; j ++ ){
            if(bits[j] == 0){
                if(t0 > 0){
                    cout << ids[j] << " ";
                    t0 -- ;
                    bits[j] = 1;
                }
            }
            else{
                if(t1 > 0){
                    cout << ids[j] << " ";
                    t1 -- ;
                    bits[j] = 0;
                }
            }
        }
        cout << endl;
        cin >> xr;
        res ^= xr;
    }
    cout << "! " << res << endl;
    return 0;
}