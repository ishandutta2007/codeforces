#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

int main() {

    string n;
    cin >> n;
    ll bAm = 0;
    ll op = 0;
    ll mod = (1e9) + 7;
    for(int i = n.size()-1;i>=0;i--){
        if(n[i] == 'b'){
            bAm++;
        }
        else{
            op+=bAm;
            bAm*=2;
            bAm%=mod;
            op%=mod;
        }
    }
    cout << op;
	return 0;
}