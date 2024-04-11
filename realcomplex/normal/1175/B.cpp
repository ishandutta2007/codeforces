#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const ll MX = (1ll << 32) - 1;

int main(){
    fastIO;
    int l;
    cin >> l;
    string op;
    stack<ll> rs;
    rs.push(1ll);
    ll res = 0;
    ll n;
    for(int i = 0 ; i < l ;i ++ ){
        cin >> op;
        if(op == "add"){
            res += rs.top();
            if(res > MX){
                cout << "OVERFLOW!!!\n";
                return 0;
            }
        }
        else if(op == "end"){
            rs.pop();
        }
        else{
            cin >> n;
            rs.push(min(rs.top() * n, MX+1));
        }
    }
    cout << res << "\n";
    return 0;
}