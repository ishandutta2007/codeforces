#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 100;
vector<int> pp[N];
int sol[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        pp[i].clear();
        pp[i].push_back(0);
        pp[i].push_back(n+1);
        sol[i]=(int)1e9;
    }
    int a;
    for(int i = 1; i <= n; i ++ ){
        cin >> a;
        pp[a].push_back(i);
    }
    int low;
    for(int i = 1; i <= n; i ++ ){
        sort(pp[i].begin(), pp[i].end());
        low = 1;
        for(int j = 1; j < pp[i].size(); j ++ ){
            low = max(low, pp[i][j] - pp[i][j-1]);
        }
        sol[low]=min(sol[low],i);
    }
    for(int i = 1; i <= n; i ++ ){
        if(i>1) sol[i] = min(sol[i], sol[i - 1]);
        if(sol[i] == (int)1e9) cout << "-1 ";
        else cout << sol[i] << " ";
    }
    cout << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ )
        solve();
    return 0;
}