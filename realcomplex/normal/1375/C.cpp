#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 10;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n; i ++ ){
        cin >> a[i];
    }
    int cn = 0;
    if(a[0] < a[n-1]){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; t ++ )
        solve();
    return 0;
}