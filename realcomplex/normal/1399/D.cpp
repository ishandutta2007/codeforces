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
    for(int t = 0; t < tc; t ++ ){
        int n;
        cin >> n;
        char f;
        vector<int> z[2];
        int cnt = 0;
        int o;
        vector<int> sol;
        for(int i = 1; i <= n; i ++ ){
            cin >> f;
            o = f - '0';
            if(z[(o^1)].size() > 0){
                sol.push_back(z[(o ^ 1)].back());
                z[o].push_back(z[(o ^ 1)].back());
                z[(o ^ 1)].pop_back();
            }
            else{
                z[o].push_back(++cnt);
                sol.push_back(cnt);
            }
        }
        cout << cnt << "\n";
        for(auto x : sol)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}