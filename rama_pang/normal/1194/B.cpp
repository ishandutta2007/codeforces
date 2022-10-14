#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll N,M,R,C;
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T; cin>>T;
    while (T--){
        ll ans=1e18;
        cin>>R>>C;
        char grid[R+5][C+5], save[R+5][C+5];
        ll rowsum[R+5], colsum[C+5];
        for (int i=1; i<=R; i++){
            ll tmp=0;
            for(int j=1; j<=C; j++){
                cin>>grid[i][j];
                if (grid[i][j]=='*'){
                    tmp++;
                }
            }
            rowsum[i]=tmp;
        }
        for (int j=1; j<=C; j++){
            ll tmp=0;
            for(int i=1; i<=R; i++){
                if (grid[i][j]=='*'){
                    tmp++;
                }
            }
            colsum[j]=tmp;
        }
        for (int i=1; i<=R; i++){
            // ll tmp=R-rowsum[i];
            for(int j=1; j<=C; j++){
                ll k=0;
                if (grid[i][j]=='.') k= -1;
                // tmp+= (C-colsum[j]);
                // cout << rowsum[i] << " " << colsum[j] << endl;
                ans=min(ans, R+C - rowsum[i] - colsum[j] +k);
                // cout << tmp << endl;

            }
        }
        
        cout << ans <<"\n";
    }

}