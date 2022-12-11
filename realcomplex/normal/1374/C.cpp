#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
    int n;
    cin >> n;
    string t;
    cin >> t;
    int mx = 0;
    for(int k = 0 ; k < n; k ++ ){
        for(int i = 0 ; i < n; i ++ ){
            for(int j = i + 1 ; j < n; j ++ ){
                if(t[i] == '(' && t[j] == ')'){
                    mx += 2;
                    t[i] = '#';
                    t[j] = '#';
                }
            }
        }
    }
    cout << (n-mx)/2 << "\n";
}

int main(){
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; t ++ ){
        solve();
    }
    return 0;
}