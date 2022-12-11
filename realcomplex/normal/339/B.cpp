#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ll n,m;
    cin >> n >> m;
    ll sk;
    ll c = 1;
    ll t = 0;
    for(int j = 0;j<m;j++){
        cin >> sk;
        if(sk>=c){
            t+=sk-c;
            c = sk;
        }
        else{
            t += (n-c) + sk;
            c = sk;
        }
    }
    cout << t;
    return 0;
}