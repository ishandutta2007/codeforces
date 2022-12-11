#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 10;
const int LOG = 30;
const int T = (int)1e7;
int nex[T][2];
int val[T][2][2];
int cnt;
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i <= cnt; i ++ ){
        nex[i][0]=nex[i][1]=-1;
        for(int p = 0 ; p < 2; p ++ ){
            for(int q = 0; q < 2; q ++ ){
                val[i][p][q]=0;
            }
        }
    }
    cnt=0;
    int x;
    int id;
    int bit;
    int pi, qi;
    int cur = 0;
    int res = 0;
    for(int i = 0 ; i < n; i ++ ){
        cin >> x;
        id = 0;
        cur = 1;
        for(int j = LOG - 1; j >= 0; j -- ){
            if(((x ^ i) & (1 << j))){
                bit = 1;
            }
            else{
                bit = 0;
            }
            pi=0;
            if((x & (1 << j))){
                pi = 1;
            }
            qi=0;
            if((i & (1 << j))){
                qi = 1;
            }
            for(int p = 0; p < 2; p ++ ){
                for(int q = 0; q < 2; q ++ ){
                    if((p ^ qi) < (pi ^ q)){
                        cur = max(cur, val[id][p][q] + 1);
                    }
                }
            }
            if(nex[id][bit] == -1){
                cnt ++ ;
                nex[id][bit] = cnt;
            }
            id = nex[id][bit];
        }
        id = 0;
        for(int j = LOG - 1; j >= 0 ; j -- ){
            if(((x ^ i) & (1 << j))){
                bit = 1;
            }
            else{
                bit = 0;
            }
            pi=0;
            if((x & (1 << j))){
                pi = 1;
            }
            qi=0;
            if((i & (1 << j))){
                qi = 1;
            }
            val[id][pi][qi] = max(val[id][pi][qi], cur);
            id = nex[id][bit];
        }
        res = max(res, cur);
    }
    cout << res << "\n";
}

int main(){
    fastIO;
    for(int i = 0 ; i < T;i ++ ){
        nex[i][0]=nex[i][1]=-1;
    }
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}