#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(ll a, ll b, ll c){
    ll mx = max({a,b,c});
    ll ad = 3ll * mx - a - b - c;
    cout << ad << endl;
    int idx;
    cin >> idx;
    if(idx == 1){
        if(a == mx){
            a += ad;
            solve(a,b,c);
        }
        else{
            a += ad;
            cout << abs(c-b) << endl;
            cin >> idx;
            return;
        }
    }
    if(idx == 2){
        if(b == mx){
            b += ad;
            solve(a, b, c);
        }
        else{
            b += ad;
            cout << abs(c-a) << endl;
            cin >> idx;
            return;
        }
    }
    if(idx == 3){
        if(c == mx){
            c += ad;
            solve(a, b, c);
        }
        else{
            c += ad;
            cout << abs(b-a) << endl;
            cin >> idx;
            return;
        }
    }
}

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    cout << "First " << endl;
    solve(a, b, c);
    return 0;
}