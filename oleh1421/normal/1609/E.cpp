#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=500010;
const ll inf=1e18;
const ll mod=998244353;
struct node{
    int dp[3][3];
    node(int c){
        for (int i=0;i<3;i++){
            for (int j=i;j<3;j++){
                if (i==j && i==c) dp[i][j]=1;
                else dp[i][j]=0;
            }
        }
    }
    node(){

    }
};
node Merge(node A,node B){
    node C;
    for (int i=0;i<3;i++){
        for (int j=i;j<3;j++){
            C.dp[i][j]=N;
            for (int t=i;t<=j;t++) C.dp[i][j]=min(C.dp[i][j],A.dp[i][t]+B.dp[t][j]);
        }
    }
    return C;
}
node t[N*4];
void upd(int v,int l,int r,int pos,int c){
    if (l==r){
        t[v]=node(c);
        return;
    }
    int m=(l+r)/2;
    if (pos<=m) upd(v+v,l,m,pos,c);
    else upd(v+v+1,m+1,r,pos,c);
    t[v]=Merge(t[v+v],t[v+v+1]);
}
void solve(int Case){
    int n,q;cin>>n>>q;
    string s;cin>>s;
    for (int i=0;i<n;i++){
        upd(1,0,n-1,i,s[i]-'a');
    }

    for (int it=1;it<=q;it++){
        int pos;cin>>pos;
        pos--;
        char c;cin>>c;
        upd(1,0,n-1,pos,c-'a');
        cout<<t[1].dp[0][2]<<endl;
    }



}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}

/**
problem B with higher constrains


3
1 R
5 R
10 R
100 G
3 G
7 G


1
4
2 3 1 4

8 1
1 3 5 2 4 7 6 8
1 8


1
5 2
-1 1 2 0 0


4 11

3 6
2 3
1 1

2 3
999999999 1000000000
**/