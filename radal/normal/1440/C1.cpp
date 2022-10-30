#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e2+30,mod = 1e9+7,inf=1e12;
string a[N];
int main(){
    int T;
    vector<pair<pair<pll,pll> , pll> >  ve;
    cin >> T;
    while(T--){
        ll n,m;
        ve.clear();
        cin >> n >> m;
        rep(i,1,n+1){
            cin >> a[i];
        }
        rep(i,1,n){
            rep(j,0,m-1){
                int cnt = 0;
                if (a[i][j] == '1') cnt++;
                if (a[i+1][j] == '1') cnt++;
                if (a[i][j+1] == '1') cnt++;
                if (a[i+1][j+1] == '1')  cnt++;
                if (cnt == 0) continue;
                if (cnt == 4){
                    ve.pb({{{i,j+2},{i+1,j+1}},{i,j+1}});
                    cnt = 1;
                    a[i][j+1] = '0';
                    a[i][j] = '0';
                    a[i+1][j] = '0';
                }
                if (cnt == 1){
                    if (a[i][j] == '1'){
                        ve.pb({{{i,j+1},{i+1,j+1}},{i+1,j+2}});
                        a[i][j] = '0';
                        a[i+1][j+1] = '1';
                        a[i+1][j] = '1';
                    }
                    else{
                        if (a[i+1][j] == '1'){
                            ve.pb({{{i,j+2},{i,j+1}},{i+1,j+1}});
                            a[i][j] = '1';
                            a[i+1][j] = '0';
                            a[i][j+1] = '1';
                        }
                        else if (a[i][j+1] == '1'){
                            ve.pb({{{i,j+1},{i+1,j+1}},{i,j+2}});
                            a[i][j] = '1';
                            a[i+1][j] = '1';
                            a[i][j+1] = '0';
                        }
                        else{
                            ve.pb({{{i,j+2},{i+1,j+2}},{i,j+1}});
                            a[i][j+1] = '1';
                            a[i][j] = '1';
                            a[i+1][j+1] = '0';
                        }
                    }
                    cnt = 2;
                }
                if (cnt == 3){
                    if (a[i][j] == '0'){
                        ve.pb({{{i,j+2},{i+1,j+1}},{i+1,j+2}});
                        a[i][j+1] = '0';
                        a[i+1][j+1] = '0';
                        a[i+1][j] = '0';
                    }
                    else{
                        if (a[i+1][j] == '0'){
                            ve.pb({{{i,j+2},{i,j+1}},{i+1,j+2}});
                            a[i][j] = '0';
                            a[i+1][j+1] = '0';
                            a[i][j+1] = '0';
                        }
                        else if (a[i][j+1] == '0'){
                            ve.pb({{{i,j+1},{i+1,j+1}},{i+1,j+2}});
                            a[i][j] = '0';
                            a[i+1][j] = '0';
                            a[i+1][j+1] = '0';
                        }
                        else{
                            ve.pb({{{i,j+2},{i+1,j+1}},{i,j+1}});
                            a[i][j+1] = '0';
                            a[i][j] = '0';
                            a[i+1][j] = '0';
                        }
                    }
                    continue;
                }
                if (cnt == 2){
                    if (a[i][j] == a[i+1][j+1]){
                        if (a[i][j] == '1'){
                            ve.pb({{{i+1,j+1},{i,j+2}},{i,j+1}});
                            ve.pb({{{i,j+2},{i+1,j+1}},{i+1,j+2}});
                            a[i][j] = '0';
                            a[i+1][j+1] = '0';
                        }
                        else{
                            ve.pb({{{i+1,j+1},{i+1,j+2}},{i,j+1}});
                            ve.pb({{{i,j+2},{i,j+1}},{i+1,j+2}});
                            a[i+1][j] = '0';
                            a[i][j+1] = '0';
                        }
                    }
                    else{
                        if (a[i][j] == a[i+1][j]){
                            if (a[i][j] == '1'){
                                ve.pb({{{i,j+2},{i+1,j+2}},{i,j+1}});
                                ve.pb({{{i,j+2},{i+1,j+2}},{i+1,j+1}});
                                a[i][j] = '0';
                                a[i+1][j] = '0';
                            }
                            else{
                                ve.pb({{{i,j+2},{i+1,j+1}},{i,j+1}});
                                ve.pb({{{i,j+1},{i+1,j+2}},{i+1,j+1}});
                                a[i][j+1] = '0';
                                a[i+1][j+1] = '0';

                            }
                        }
                        else{
                            if (a[i][j] == '1'){
                                ve.pb({{{i+1,j+1},{i+1,j+2}},{i,j+1}});
                                ve.pb({{{i,j+2},{i+1,j+2}},{i+1,j+1}});
                                a[i][j] = '0';
                                a[i][j+1] = '0';
                            }
                            else{
                                ve.pb({{{i,j+2},{i+1,j+1}},{i,j+1}});
                                ve.pb({{{i,j+1},{i+1,j+2}},{i,j+2}});
                                a[i+1][j] = '0';
                                a[i+1][j+1] = '0';
                            }

                        }
                    }
                }
            }
        }
        cout << ve.size() << endl;
        for (auto U : ve){
            cout << U.X.X.X << ' ' << U.X.X.Y <<' '<< U.X.Y.X<< ' ' <<U.X.Y.Y << ' ' << U.Y.X << ' ' << U.Y.Y << endl;
        }
    }
}