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
    for(int ti = 1; ti <= tc; ti ++ ){
        int n, k;
        cin >> n >> k;
        vector<int> sol;
        for(int i = (k+1)/2; i < k ; i ++ )
            sol.push_back(i);
        for(int i = k + 1; i <= n; i ++ )
            sol.push_back(i);
        cout << sol.size() << "\n";
        for(auto x : sol)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}