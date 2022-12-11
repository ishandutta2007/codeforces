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
    for(int t = 1; t <= tc; t ++ ){
        int a, b;
        cin >> a >> b;
        int low = (int)1e9;
        int nw;
        int cur;
        int gg;
        for(int ad = 0; ad < 1000 ; ad ++ ){
            nw = b + ad;
            if(nw == 1) continue;
            cur = ad;
            gg = a;
            while(gg > 0){
                gg /= nw;
                cur ++ ;
            }
            low = min(low, cur);
        }
        cout << low << "\n";
    }
    return 0;
}