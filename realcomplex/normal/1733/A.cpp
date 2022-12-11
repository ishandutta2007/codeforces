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
        int n, k;
        cin >> n >> k;
        vector<int> f(k);
        int a;
        for(int i = 0 ; i < n; i ++ ){
            cin >> a;
            f[i % k] = max(f[i % k], a);
        }
        ll sum = 0;
        for(int i = 0 ; i < k ; i ++ ){
            sum += f[i];
        }
        cout << sum << "\n";
    }
    return 0;
}