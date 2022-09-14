#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
///use char if you want a naive algorithm to pass
#include <bits/stdc++.h>
//#include <vector>
#define endl '\n'
typedef long long ll;
using namespace std;

const int N=9;
int a[N][N];
void solve(){
    cout<<endl;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            char c;cin>>c;
            a[i][j]=(c-'0');
        }
    }
    vector<pair<int,int> >v;
    v.push_back({0,0});
    v.push_back({1,3});
    v.push_back({2,6});
    v.push_back({3,1});
    v.push_back({4,4});
    v.push_back({5,7});
    v.push_back({6,2});
    v.push_back({7,5});
    v.push_back({8,8});
    for (auto cur:v){
        int i=cur.first;
        int j=cur.second;;
        if (a[i][j]==1) a[i][j]=2;
        else a[i][j]=1;
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}