#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 25;
int A[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }
    int g;
    for(int i = n + 1; i >= n-1; i --) {
        g = 0;
        for(int j = 1; j <= n; j ++ ){
            if(j == i){
                g = __gcd(g, __gcd(A[j], j));
            }
            else{
                g = __gcd(g, A[j]);
            }
        }
        if(g == 1){
            cout << n - i + 1 << "\n";
            return;
        }
    }
    cout << 3 << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}