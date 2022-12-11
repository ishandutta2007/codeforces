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
        ll n;
        cin >> n;
        ll li = 0, ri = (ll)2e9;
        ll mid;
        ll aa, bb;
        while(li + 1 < ri){
            mid = (li + ri) / 2ll;
            aa = 2ll * mid + 1;
            bb = (aa * aa - 1) / 2ll;
            if(bb > n || (aa * aa - bb) > n){
                ri = mid;
            }
            else{
                li = mid;
            }
        }
        cout << li << "\n";
    }
    return 0;
}