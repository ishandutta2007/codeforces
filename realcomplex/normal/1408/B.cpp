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
    int n, k;
    for(int t = 1; t <= tc; t ++ ){
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> a[i];
        }
        vector<vector<int>> sol;
        int cur = 0;
        int rem;
        while(a[n-1] > 0){
            cur = 0;
            rem = 0;
            sol.push_back({});
            sol.back().resize(n);
            for(int i = 0 ; i < n; i ++ ){
                a[i] -= rem;
                if(a[i] > 0 && cur < k){
                    rem += a[i];
                    a[i] = 0;
                    cur ++ ;
                }
                else if(i == 0) cur ++ ;
                sol.back()[i] = rem;
            }
            if(rem == 0){
                break;
            }
        }
        if(a[n-1] == 0)
            cout << sol.size() << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}