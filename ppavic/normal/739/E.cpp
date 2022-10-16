#include <cstdio>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long double db;

const int N = 2005;
const db INF = 1e30;

int rek[N], n, a, b, col[N], cnt = 1;
db c, p[N], q[N], dp[N], c2;

db f(int i){
    if(col[i] == cnt) return dp[i];
    if(i == n) return 0;
    db ret = -INF;
    if(f(i + 1) > ret)
        ret = f(i + 1), rek[i] = 0;
    if(f(i + 1) + p[i] - c2 > ret)
        ret = f(i + 1) + p[i] - c2, rek[i] = 1;
    if(f(i + 1) + q[i] - c  > ret)
        ret = f(i + 1) + q[i] - c, rek[i] = 2;
    if(f(i + 1) + p[i] + q[i] - p[i] * q[i] - c - c2 > ret)
        ret = f(i + 1) + p[i] + q[i] - p[i] * q[i] - c - c2 , rek[i] = 3;
    col[i] = cnt;
    return dp[i] = ret;
}

int check(int sm = 0, int en = 0){
    db sol = f(0);cnt++;
    int ci = 0, ca = 0, cb = 0;
    while(ci != n){
        if(rek[ci] == 2 || rek[ci] == 3) cb++;
        if(rek[ci] == 1 || rek[ci] == 3) ca++;
        ci++;
    }
    if(en){
        cout <<  fixed << setprecision(10) << sol + c * (db)b + c2 * (db)a << " " << endl;
    }
    if(sm)return ca;
    else return cb;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b;
    if(a == b && b == 0){
        cout << 0; return 0;
    }
    for(int i = 0;i<n;i++)
        cin >> p[i];
    for(int i = 0;i<n;i++)
        cin >> q[i];
    db lo = 0, hi = 2, lo2 = 0, hi2 = 2;
    for(int i = 0;i<30;i++){
        c = (lo + hi) / 2;
        lo2 = 0, hi2 = 2;
        for(int j = 0;j<30;j++){
            c2 = (lo2 + hi2) / 2;
            int x = check(1);
            if(x <= a){
                hi2 = c2;
            }
            else{
                lo2 = c2;
            }
        }
        c2 = hi2;
        int x = check(0);
        if(x <= b){
            hi = c;
        }
        else{
            lo = c;
        }
    }
    c = hi;
    check(0,1);
}