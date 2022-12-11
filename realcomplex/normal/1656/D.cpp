#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool check(ll n, ll k){
    ll res = n - (k * 1ll * (k - 1)) / 2ll;
    if(res <= 0){
        return false;
    }
    return (res % k == 0);
}



int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        ll n;
        cin >> n;
        if(n % 2 == 1){
            cout << 2 << "\n";
        }
        else{
            ll p = 1;
            while(1){
                p *= 2ll;
                if((p * 1ll * (p - 1)) / 2ll >= n){
                    p = -1;
                    break;
                }
                if(check(n, p)){
                    break;
                }
            }
            if(p != -1){
                cout << p << "\n";
                continue;
            }
            while(n % 2 == 0) n /= 2;
            if(n == 1){
                cout << "-1\n";
            }
            else{
                cout << n << "\n";
            }
        }
    }
    return 0;
}