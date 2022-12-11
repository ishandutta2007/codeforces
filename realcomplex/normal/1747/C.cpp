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
        for(int i = 0 ; i < n; i ++ ){
            cin >> a[i];
        }
        ll low = (ll)1e9 + 10;
        for(int i = 1; i < n; i ++ ){
            low = min(low, a[i]);
        }
        if(a[0] > low){
            cout << "Alice\n";
        }
        else{
            cout << "Bob\n";
        }
    }
    return 0;
}