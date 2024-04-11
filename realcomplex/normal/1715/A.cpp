#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef pair<ld, ld> pdd;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n, m;
        cin >> n >> m;
        if(n > 1)
            cout << min(2 * (m - 1) + n, (n + m - 2) + n) << "\n";
        else{
            if(m == 1)cout << 0 << "\n";
            else cout << m << "\n";
        }
    }
    return 0;
}