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
    int q;
    cin >> q;
    for(int i = 0 ; i < q; i ++ ){
        ll a, b, c;
        cin >> a >> b >> c;
        cout << (a + b + c) / 2 << "\n";
    }
    return 0;
}