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
    for(int iq = 1; iq <= tc; iq ++ ){
        ll a, b;
        cin >> a >> b;
        if(b == 1){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << a * b << " " << a << " " << a * b + a << "\n";
    }
    return 0;
}