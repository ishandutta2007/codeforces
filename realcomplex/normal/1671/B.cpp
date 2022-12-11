#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
ll X[N];
void solve(){
    int n;
    cin >> n;
    for(int i = 0 ; i <= n + 1; i ++ ){
        X[i] = 0;
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> X[i];
    }
    if(X[n] - X[1] + 1 <= n + 2){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}