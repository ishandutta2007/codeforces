#include "bits/stdc++.h"
using namespace std;
const int N = 2105;
string a , b;
int n , m;
int lcpf[N][N];
int lcpr[N][N];
int cur = 1;
int ansl[N];
int ansr[N];
int cnt = 0;
int main(){
    cin >> a >> b;
    n = a.size();
    m = b.size();
    a = " " + a;
    b = " " + b;
    for(int i = m ; i >= 1 ; --i){
        for(int j = 1 ; j <= n ; ++j){
            if(a[j] == b[i]){
                lcpf[i][j] = lcpf[i + 1][j + 1] + 1;
                lcpr[i][j] = lcpr[i + 1][j - 1] + 1;
            }
        }
    }
    while(cur <= m){
        int l = 0;
        int r = -1;
        bool ok = 1;
        for(int j = 1 ; j <= n ; ++j){
            int tmp = lcpf[cur][j];
            if(!tmp){
                continue;
            }
            if(ok || tmp > r - l + 1){
                l = j;
                r = j + tmp - 1;
                ok = 0;
            }
        }
        for(int j = 1 ; j <= n ; ++j){
            int tmp = lcpr[cur][j];
            if(!tmp){
                continue;
            }
            if(ok || tmp > abs(r - l) + 1){
                l = j;
                r = j - tmp + 1;
                ok = 0;
            }
        }
        if(ok){
            cout << "-1\n";
            return 0;
        }
        ansl[++cnt] = l;
        ansr[cnt] = r;
        cur += abs(r - l) + 1;
    }
    cout << cnt << "\n";
    for(int i = 1 ; i <= cnt ; ++i){
        cout << ansl[i] << " " << ansr[i] << "\n";
    }
}