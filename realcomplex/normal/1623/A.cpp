#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n, m, ii, jj, ti, tj;
        cin >> n >> m >> ii >> jj >> ti >> tj;
        int res = 0;
        int di = +1;
        int dj = +1;
        while(ii != ti && jj != tj){
            if(ii == n){
                di = -1;
            }
            else if(ii == 1){
                di = +1;
            }
            if(jj == 1){
                dj = +1;
            }
            else if(jj == m){
                dj = -1;
            }
            ii += di;
            jj += dj;
            res ++ ;
        }
        cout << res << "\n";
    }
    return 0;
}