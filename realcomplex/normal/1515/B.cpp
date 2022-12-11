#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool chk(int x){
    int q = sqrt(x);
    return ((q * q) == x);
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        bool sol = false;
        if(n % 2 == 0 && chk(n/2)){
            sol = true;
        }
        if(n % 4 == 0 && chk(n/4)){
            sol = true;
        }
        if(sol)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}