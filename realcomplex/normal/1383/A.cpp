#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
    int n;
    cin >> n;
    string A,B;
    cin >> A >> B;
    for(int i = 0 ; i < n; i ++ ){
        if(A[i] > B[i]){
            cout << "-1\n";
            return;
        }
    }
    int ans = 0;
    char low;
    char cur;
    for(int let = 0; let < 20; let ++ ){
        cur = 'a' + let;
        low = 'z';
        vector<bool> has(20);
        for(int i = 0 ; i < n; i ++ ){
            if(A[i] == cur){
                if(B[i] != A[i]){
                    low = min(low, B[i]);
                }
            }
        }
        if(low == 'z') continue;
        ans ++ ;
        for(int i = 0 ; i < n; i ++ ){
            if(A[i] == cur && B[i] != A[i])
                A[i] = low;

        }
    }
    cout << ans << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; t ++ )
        solve();
    return 0;
}