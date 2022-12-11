#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int query(int a, int b){ // we solvin for x + 1
    int res;
    cout << "? " << a << " " << b << endl;
    cin >> res;
    return res;
}

void solve(){
    int d = 1;
    int f;
    int known = 0;
    int g;
    for(int bit = 0; bit < 30; bit ++ ){
        f = (d - known);
        d <<= 1;
        g = query(f, f + d);
        if(g == d){
            known += (1 << bit);
        }
    }
    cout << "! " << known << endl;
}

int main(){
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}