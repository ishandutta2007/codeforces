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
        vector<int> a(n);
        int low  = (int)1e9;
        int soln = 0;
        for(int i = 0 ; i < n; i ++ ){
            cin >> a[i];
            low = min(low, a[i]);
        }
        for(int i = 0 ; i < n; i ++ ){
            soln += ((a[i] - 1) / (2 * low - 1));
        }
        cout << soln << "\n";
    }
    return 0;
}