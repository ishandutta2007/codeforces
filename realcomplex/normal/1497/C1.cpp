#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int tc;
    cin >> tc;
    int n, k;
    ll daq;
    for(int t = 1; t <= tc; t ++ ){
        cin >> n >> k;
        ll aa = (n - 1) / 2;
        if(n % 4 == 0){
            cout << (n/4) << " " << (n/4) << " " << (n/2) << "\n";
        }
        else{
            cout << aa << " " << aa << " " << n - 2ll * aa << "\n";
        }
    }
    return 0;
}