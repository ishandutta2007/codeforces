#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;

map<ll, ll> res;
set<ll> has;

int main(){
    fastIO;
    int q;
    cin >> q;
    char typ;
    ll x;
    has.insert(0ll);
    for(int iq = 1; iq <= q; iq ++ ){
        cin >> typ >> x;
        if(typ == '+'){
            has.insert(x);
        }
        else{
            while(has.count(res[x])) res[x] += x;
            cout << res[x] << "\n";
        }
    }
    return 0;
}