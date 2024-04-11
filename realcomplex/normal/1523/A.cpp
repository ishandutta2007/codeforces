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
        int n, k;
        cin >> n >> k;
        string t;
        cin >> t;
        string nw;
        for(int it = 0; it < min(n, k); it ++ ){
            nw = t;
            for(int j = 0 ; j < n; j ++ ){
                if(t[j] == '0'){
                    if(j > 0 && j + 1 < n && t[j - 1] == '1' && t[j + 1] == '1') continue;
                    if(j > 0 && t[j - 1] == '1') nw[j] = '1';
                    if(j + 1 < n && t[j + 1] == '1') nw[j] = '1';
                }
            }
            t = nw;
        }
        cout << t << "\n";
    }
    return 0;
}