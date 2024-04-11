#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
const int M = N * 2 + 512;
int a[N];
int c[N * 2];

void solve(){
    int n, m;
    cin >> n >> m;
    char f;
    int cnt = 0;
    for(int i = 1; i <= n; i ++ ){
        cin >> f;
        a[i] = f - '0';
        cnt += a[i];
        c[i] = a[i];
        c[i + n] = a[i];
    }
    // q/m = cnt/n => m * cnt = q * n => q = m * cnt / n
    if((m * 1ll * cnt) % n != 0){
        cout << "-1\n";
        return;
    }

    int q = (m * 1ll * cnt) / n;
    int cur = 0;
    for(int j = 1; j <= m ; j ++ ) cur += c[j];
    for(int i = 1; i + m - 1 <= 2 * n; i ++ ){
        if(cur == q){
            if(i + m - 1 > n){
                cout << 2 << "\n";
                cout << 1 << " " << i + m - 1 - n << "\n";
                cout << i << " " << n << "\n";
                return;
            }
            else{
                cout << "1" << "\n" << i << " " << i + m - 1 << "\n";
                return;
            }
        }
        cur -= c[i];
        cur += c[i + m];
    }
    cout << -1 << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}