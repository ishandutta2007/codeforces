#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; t ++ ){
        ll a, b, n, m;
        cin >> a >> b >> n >> m;
        if(a < b) swap(a, b);
        if(m > b){
            cout << "NO\n";
            continue;
        }
        b -= m;
        if(a + b >= n){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}