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
        int n, x;
        cin >> n >> x;
        vector<int> W(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> W[i];
        }
        sort(W.begin(), W.end());
        int cur = 0;
        bool soln = true;
        for(int i = 0 ; i < n; i ++ ){
            cur += W[i];
            if(cur == x){
                if(i == n - 1){
                    soln = false;
                }
                else{
                    swap(W[i], W[i + 1]);
                }
            }
        }
        if(soln){
            cout << "YES\n";
            for(auto x : W)
                cout << x << " ";
            cout << "\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}