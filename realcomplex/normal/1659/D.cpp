#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int c[N];
int a[N];
int d[N];
void solve(){
    int n;
    cin >> n;
    for(int i = 0 ; i <= n + 1; i ++ ){
        c[i] = a[i] = d[i] = 0;
    }
    ll S = 0;
    for(int i = 1; i <= n; i ++ ){
        cin >> c[i];
        S += c[i];
    }
    // induct on n
    int ones = S / (ll)n;
    int was = 0;
    int dec = 0;
    for(int i = n; i >= 1; i -- ){
        /*
        for(int j = 0; j < ones; j ++ ){
            c[i - j] -- ;
        }
        */
        dec -= d[i];
        c[i] -= dec;
        was = 0;
        if(c[i] == i){
            a[i] = 1;
            was = 1;
        }
        else if(c[i] == 1){
            a[i] = 0;
        }
        else{
            for(int j = i ; j >= 1; j -- ){
                c[j] = 0;
            }
            break;
        }
        dec ++ ;
        d[i - ones] ++ ;
        if(was) ones -- ;
    }
    if(c[1] == 1) a[1] = 1;
    else a[1] = 0;
    for(int i = 1; i <= n; i ++ ){
        cout << a[i] << " ";
    }
    cout << "\n";
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