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
    for(int t = 1; t <= tc; t ++ ){
        int n,m;
        vector<int> A, B;
        cin >> n;
        A.push_back(0);
        int x;
        for(int i = 1; i <= n; i ++ ){
            cin >> x;
            A.push_back(A.back() + x);
        }
        B.push_back(0);
        cin >> m;
        for(int i = 1; i <= m ; i ++ ){
            cin >> x;
            B.push_back(B.back() + x);
        }
        int ans = 0;
        for(auto i : A){
            for(auto j : B){
                ans = max(ans, i + j);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}