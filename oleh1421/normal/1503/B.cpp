#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
using namespace std;
//#define __int128_t ll
const int N=2010;
int a[N][N];
vector<pair<int,int> >g[2];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            g[(i+j)%2].push_back({i,j});
        }
    }
    for (int it=1;it<=n*n;it++){
        int c;cin>>c;
        if (c!=1){
            if (g[0].empty()){
                if (c==2){
                    cout<<3<<" "<<g[1].back().first<<" "<<g[1].back().second<<endl;
                } else {
                    cout<<2<<" "<<g[1].back().first<<" "<<g[1].back().second<<endl;
                }
                g[1].pop_back();
            } else {
                cout<<1<<" "<<g[0].back().first<<" "<<g[0].back().second<<endl;
                g[0].pop_back();
            }
        } else {
            if (g[1].empty()){
                cout<<3<<" "<<g[0].back().first<<" "<<g[0].back().second<<endl;
                g[0].pop_back();
            } else {
                cout<<2<<" "<<g[1].back().first<<" "<<g[1].back().second<<endl;
                g[1].pop_back();
            }
        }

        cout<<endl;
    }


//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=n;j++){
//            cout<<a[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return;

}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }


    return 0;
}
/**
1
5 5 100
4
5
4
3
1
OK
FAIL
OK
OK
OK
FAIL
OK

0 1 0 0 0

1
5 5 100
4
5
4
2
1

FAIL
FAIL
FAIL
OK
FAIL
OK
OK
FAIL
FAIL
FAIL
OK


! 10
**/