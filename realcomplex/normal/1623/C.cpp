#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        vector<ll> h(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> h[i];
        }
        ll li = 1;
        ll ri = (ll)2e9;
        ll mid;
        bool can;
        ll X;
        ll send;
        while(li + 1 < ri){
            mid = (li + ri) / 2;
            can = true;
            vector<ll> H = h;
            vector<ll> extra(n);
            for(int i = n - 1; i >= 0; i -- ){
                if(H[i] + extra[i] < mid){
                    can = false;
                    break;
                }
                if(i >= 2){
                    send = min((H[i] + extra[i] - mid) / 3ll, (H[i] / 3ll));
                    extra[i - 1] += send;
                    extra[i - 2] += 2ll * send;
                }
            }
            if(can){
                li = mid;
            }
            else{
                ri = mid;
            }
        }
        cout << li << "\n";
    }
    return 0;
}