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
    for(int t = 1; t <= tc; t ++ ){
        int n;
        cin >> n;
        int a;
        cin >> a;
        int b;
        int res = 1;
        for(int i = 2; i <= n; i ++ ){
            cin >> b;
            if(b != a) res = 0;
            a = b;
        }
        if(!res) cout << 1 << "\n";
        else cout << n << "\n";
    }
    return 0;
}