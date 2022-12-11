#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        int n;
        cin >> n;
        set<int> vals;
        vector<int> x(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> x[i];
        }
        for(int i = 0 ; i < n; i ++ ){
            for(int j = i + 1; j < n; j ++ ){
                vals.insert(x[j]-x[i]);
            }
        }
        cout << vals.size() << "\n";
    }
    return 0;
}