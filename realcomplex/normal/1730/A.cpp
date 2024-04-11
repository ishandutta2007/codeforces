#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int t[105];

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n, c;
        cin >> n >> c;
        for(int i = 0 ; i < 105; i ++ ) t[i] = 0;
        int x;
        for(int i = 1; i <= n; i ++ ){
            cin >> x;
            t[x] ++ ;
        }
        int soln = 0;
        for(int i = 0 ; i < 105; i ++ ){
            soln += min(c, t[i]);
        }
        cout << soln << "\n";
    }
    return 0;
}