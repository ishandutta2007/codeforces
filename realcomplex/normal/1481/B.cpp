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
    for(int qr = 0; qr < tc; qr ++ ){
        int n, k;
        cin >> n >> k;
        vector<int> h(n);
        for(int i = 0 ;i  < n; i ++ ){
            cin >> h[i];
        }
        int soln = n;
        for(int i = 0 ; i < k ; i ++ ){
            for(int j = 0 ; j < n; j ++ ){
                if(j == n - 1){
                    soln = -2;
                    break;
                }
                if(h[j] < h[j + 1]){
                    h[j] ++ ;
                    soln = j;
                    break;
                }
            }
            if(soln == -2) break;
        }
        cout << soln + 1 << "\n";
    }
    return 0;
}