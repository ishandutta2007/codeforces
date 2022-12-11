#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1005;
int cnt[N];

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n; i ++ ){
        cin >> a[i];
    }
    vector<int> sol;
    int p;
    while(1){
        p = -1;
        for(int i = 0 ; i < n; i ++ )
            if(a[i] != i){
                if(i == n - 1 && a[i] == n) continue;
                p = i;
                break;
            }
        if(p == -1) break;
        for(int j = 0 ; j <= n + 1; j ++ )
            cnt[j] = 0;
        int mex = 0;
        for(int j = 0 ; j < n; j ++ )
            cnt[a[j]] ++ ;
        while(cnt[mex] > 0) mex ++ ;
        if(mex == p){
            a[p] = mex;
            sol.push_back(p);
        }
        else{
            if(mex == n){
                a[n-1] = mex;
                sol.push_back(n-1);
            }
            else if(mex > a[mex]){
                a[mex] = mex;
                sol.push_back(mex);
            }
            else{
                for(int i = 0 ; i < n; i ++ ){
                    if(a[i] == p){
                        sol.push_back(i);
                        a[i]=mex;
                        break;
                    }
                }
            }
        }
    }
    cout << sol.size() << "\n";
    for(auto x : sol)
        cout << x + 1 << " ";
    cout << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; t ++ ){
        solve();
    }
    return 0;
}