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

const int MOD = (int)1e9 + 7;

int f[16];

int ret[16][16][16][16][4];
bool vis[16][16][16][16][4];

int n;
int brute(int id, int c0, int c1, int c2, int last){
    if(c0 == 0 && c1 == 0 && c2 == 0)
        return 1;
    if(vis[id][c0][c1][c2][last] == true)
        return ret[id][c0][c1][c2][last];
    int res= 0 ;
    if(c0 > 0 && last != 1)
        res += brute(id + 1, c0 - 1, c1, c2, 1);
    if(c1 > 0 && last != 2)
        res += brute(id + 1, c0, c1 - 1, c2, 2);
    if(c2 > 0 && last != 3)
        res += brute(id + 1, c0, c1, c2 - 1, 3);
    vis[id][c0][c1][c2][last] = true;
    ret[id][c0][c1][c2][last] = res;
    return res;
}

void add(int &a, int b){
    a += b;
    if(a > MOD)
        a -= MOD;
}

int mult(int a, int b){
    return (a * 1ll * b) % MOD;
}

int main(){
    fastIO;
    int T;
    cin >> n >> T;
    int t[n], g[n];
    for(int i = 0 ; i < n ; i ++ ){
        cin >> t[i] >> g[i];
    }
    f[0] = 1;
    for(int i = 1; i <= n; i ++ )
        f[i] = (f[i-1]*1ll*i)%MOD;
    int sum;
    int cnt[4];
    int m;
    int res = 0;
    int cur;
    for(int i = 0 ; i < (1 << n); i ++ ){
        sum = 0;
        for(int j = 0 ; j < 4; j ++ )
            cnt[j] = 0;
        m = 0;
        for(int j = 0 ; j < n ; j ++ ){
            if(i & (1 << j)){
                cnt[g[j]] ++;
                sum += t[j];
                m ++ ;
            }
        }
        if(sum != T)
            continue;
        cur = brute(0, cnt[1], cnt[2], cnt[3], 0);
        cur = mult(cur, f[cnt[1]]);
        cur = mult(cur, f[cnt[2]]);
        cur = mult(cur, f[cnt[3]]);
        add(res, cur);
    }
    cout << res;
    return 0;
}