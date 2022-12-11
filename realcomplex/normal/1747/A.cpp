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
        vector<ll> a(n);
        ll s0 = 0;
        ll s1 = 0;
        for(int i = 0 ; i < n; i ++ ){
            cin >> a[i];
            if(a[i] < 0) s0 -= a[i];
            else s1 += a[i];
        }
        cout << abs(s0-s1) << "\n";
    }
    return 0;
}