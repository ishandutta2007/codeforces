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
        int n, m;
        cin >> n >> m;
        int i,j;
        i = j = 1;
        bool good;
        for(int p = 1; p <= n; p ++ ){
            for(int q = 1; q <= m; q ++ ){
                good = false;
                for(int a = -2; a <= 2; a ++ ){
                    for(int b = -2; b <= 2; b ++ ){
                        if(abs(a) == abs(b)) continue;
                        if(a == 0 || b == 0) continue;
                        if(p + a >= 1 && p + a <= n && q + b >= 1 && q + b <= m){
                            good = true;
                        }
                    }
                }
                if(!good){
                    i = p;
                    j = q;
                }
            }
        }
        cout << i << " " << j << "\n";
    }
    return 0;
}