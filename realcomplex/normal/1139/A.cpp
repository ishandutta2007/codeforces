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
    int n;
    cin >> n;
    char x;
    ll ans =0 ;
    for(int i = 1; i <= n; i ++ ){
        cin >> x;
        if((x - '0') % 2 == 0) ans += i;
    }
    cout << ans;
    return 0;
}