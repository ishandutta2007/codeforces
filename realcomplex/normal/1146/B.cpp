#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

int main(){
    fastIO;
    string t;
    cin >> t;
    string nw;
    for(auto p : t)
        if(p != 'a')
            nw.push_back(p);
    int m = nw.size();
    if(m % 2 == 1){
        cout << ":(";
        return 0;
    }
    int n = m/2;
    for(int i = 0 ; i < n; i ++ ){
        if(nw[i] != nw[i + n]){
            cout << ":(";
            return 0;
        }
    }
    int r = n;
    for(int i = (int)t.size() - 1; i >= 0 ; i -- ){
        if(r == 0)
            break;
        if(t[i] != 'a'){
            r = max(0,r-1);
        }
        else{
            cout << ":(";
            return 0;
        }
    }
    for(auto p : t){
        if(p == 'a'){
            cout << p ;
        }
        else{
            if(n > 0){
                cout << p;
                n -- ;
            }
        }
            
    }
    return 0;
}