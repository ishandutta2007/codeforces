#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 505;
vector<int> dp[N];
int A[N];

int mod;

int getlow(int x){
    if(x == 0 || x == mod - 1) return 0;
    return x - 1;
}

void solve(){
    int n;
    cin >> n >> mod;
    char f;
    for(int i = 1; i <= n; i ++ ){
        cin >> f;
        dp[i].clear();
        A[i]=f-'a';
    }
    int low;
    vector<int> pv;
    int las;
    for(int i = 1; i <= n; i ++ ){
        low = getlow(A[i]);
        pv = dp[i - 1];
        dp[i] = pv;
        dp[i].push_back(low);
        if(i > 1){
            pv = dp[i - 1];
            pv.push_back(A[i]);
            swap(pv[pv.size() - 2], pv[pv.size() - 1]);
            dp[i] = min(dp[i], pv);

            pv = dp[i - 2];
            pv.push_back(low);
            pv.push_back(A[i-1]);
            dp[i] = min(dp[i],pv);
        }
        if(i > 2){
            pv = dp[i - 2];
            las = pv.back();
            pv.pop_back();
            pv.push_back(A[i]);
            pv.push_back(las);
            pv.push_back(A[i-1]);
            dp[i] = min(dp[i],pv);
        }
    }
    for(auto x : dp[n]){
        cout << char(x+'a');
    }
    cout << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1;  t <= tc; t ++ ){
        solve();
    }
    return 0;
}