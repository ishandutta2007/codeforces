#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

void query(ll l){
    if(l%2==1){
        if(l<9||l==11){
            cout << -1;
        }
        else{
            cout << l/4-1;
        }
    }
    else{
        if(l == 2) cout << -1;
        else cout << l/4;
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin >> q;
    ll n;
    for(int j = 0;j<q;j++){
        cin >> n;
        query(n);
    }
    return 0;
}