#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 100;
int a[N];

vector<int> sheep[4];

int main(){
    fastIO;
    int n;
    cin >> n;
    vector<pii> sol;
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i];
    }
    int low = n;
    int id;
    for(int i = n; i >= 1; i -- ){
        if(a[i] == 0) continue;
        if(a[i] == 1){
            sheep[1].push_back(i);
        }
        else if(a[i] == 2){
            if(sheep[1].empty()){
                cout << "-1\n";
                return 0;
            }
            int id = sheep[1].back();
            sheep[1].pop_back();
            sol.push_back(mp(low, id));
            sol.push_back(mp(low, i));
            sheep[2].push_back(i);
            low--;
        }
        else{
            int idx = -1;
            if(!sheep[3].empty()) idx = 3;
            else if(!sheep[2].empty()) idx = 2;
            else if(!sheep[1].empty()) idx = 1;
            if(idx == -1){
                cout << "-1\n";
                return 0;
            }
            id = sheep[idx].back();
            sheep[idx].pop_back();
            if(idx == 1){
                sol.push_back(mp(low-1, id));
                sol.push_back(mp(low, id));
                sol.push_back(mp(low-1, i));
                low -= 2;
            }
            else{
                sol.push_back(mp(low, id));
                sol.push_back(mp(low, i));
                low--;
            }
            sheep[3].push_back(i);

        }
    }
    for(auto x : sheep[1]){
        sol.push_back(mp(low, x));
        low -- ;
    }
    cout << sol.size() << "\n";
    for(auto x : sol)
        cout << x.fi << " " << x.se << "\n";
    return 0;
}