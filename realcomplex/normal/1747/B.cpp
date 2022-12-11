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
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        vector<pii> op;
        for(int i = 1; i <= 3 * n; i += 3 ){
            if(i < 3 * n - i + 1){
                op.push_back(mp(i, 3 * n - i + 1));
            }
        }
        cout << op.size() << "\n";
        for(auto x : op){
            cout << x.fi << " " << x.se << "\n";
        }
    }
    return 0;
}