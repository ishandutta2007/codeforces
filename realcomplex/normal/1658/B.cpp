#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1050;
const int MOD = 998244353;
int F[N];

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    F[0] = 1;
    for(int i = 1; i < N ; i ++ ){
        F[i] = (F[i - 1] * 1ll * i) % MOD;
    }
    int tc;

    cin >> tc;
    int res;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        if(n % 2 == 1){
            cout << "0\n";
        }
        else{
            res = F[n/2];
            res = (res * 1ll * res) % MOD;
            cout << res << "\n";
        }
    }
    return 0;
}