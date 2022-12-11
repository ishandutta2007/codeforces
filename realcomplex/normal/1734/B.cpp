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
        int n;
        cin >> n;
        for(int i = 1; i <= n; i ++ ){
            for(int j = 1; j <= i ; j ++ ){
                if(j == 1 || j == i) cout << 1 << " ";
                else cout << 0 << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}