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
        int n;
        cin >> n;
        int g = 0;
        int a ;
        for(int i = 1; i <= n; i ++ ){
            cin >> a;
            g = __gcd(g, a);
        }
        cout << a/g << "\n";
    }
    return 0;
}