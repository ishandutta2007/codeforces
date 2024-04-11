#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t =0 ; t < tc; t ++ ){
        int n;
        cin >> n;
        int mn = 102;
        int mx = 0;
        int a;
        set<int> ele;
        for(int i = 1; i <= n; i ++ ){
            cin >> a;
            ele.insert(a);
            mn = min(mn, a);
            mx = max(mx, a);
        }
        if(mx - mn + 1 == ele.size()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}