#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1010;
const int K = 20;
int c[N][K];
map<ll, int> cnt;
int q[N];
int main(){
    fastIO;
   // freopen("in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    ll p, pw;
    for(int i = 0 ; i < n; i ++ ){
        p = 0;
        pw = 1;
        for(int j = 0 ; j < k ; j ++ ){
            cin >> c[i][j];
            p += pw * 1ll * c[i][j];
            pw *= 3ll;
        }
        cnt[p] ++ ;
    }
    int d;
    for(int i = 0 ; i < n; i ++ ){
        for(int j = i + 1; j < n; j ++ ){
            pw = 1;
            p = 0;
            for(int t = 0; t < k; t ++ ){
                d = (6 - c[i][t] - c[j][t]) % 3;
                p += d * pw;
                pw *= 3ll;
            }
            if(cnt.count(p)){
                q[i]++;
                q[j]++;
            }
        }
    }
    int res = 0;
    for(int i = 0 ; i < n; i ++ ){
        q[i] /= 2;
        res += (q[i] * 1ll * (q[i] - 1)) / 2;
    }
    cout << res << "\n";
    return 0;
}