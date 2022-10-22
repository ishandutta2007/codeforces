#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll mod = 1000000007ll;
ll n,m,k,x,y;

ll num;

ll M[100][100] = {0};

void solve(){

ll km = k%num;
for(ll c1 = 0; c1 < n; c1++){
    for(ll c2 = 0; c2 < m; c2++){
        if(km == 0)return;
        M[c1][c2]++;
        km--;
    }
}

for(ll c1 = n-2; c1 > 0; c1--){
    for(ll c2 = 0; c2 < m; c2++){
        if(km == 0)return;
        M[c1][c2]++;
        km--;
    }
}
return;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll c1,c2,c3,c4,c5;
    ll a,b,c;
    cin >> n >> m >> k >> x >> y;
    x--;
    y--;
    num = m * (n-2) * 2 + 2*m;

    if(n == 1){

        ll km = k%m;

        for(c1 = 0; c1 < m; c1++){
            M[0][c1] += k/m;
        }

        for(c1 = 0; c1 < km; c1++){
            M[0][c1]++;
        }

        cout << M[0][0] << " " << M[0][m-1] << " " << M[x][y] << "\n";
    }
    else{

        for(c1 = 0; c1 < n; c1++){
            for(c2 = 0; c2 < m; c2++){
                if(c1 == 0 || c1 == n-1){
                    M[c1][c2] += k/num;
                }
                else{
                     M[c1][c2] += 2*(k/num);
                }
            }
        }
        solve();

        ll mi = M[0][0];
        ll ma = -1;

        for(c1 = 0; c1 < n; c1++){
            for(c2 = 0; c2 < m; c2++){
                mi = min(mi , M[c1][c2]);
                ma = max(ma , M[c1][c2]);

            }

        }

        cout << ma << " " << mi << " " << M[x][y] << "\n";

    }
    return 0;
}