//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//#define int ll
#define endl '\n'
const int N=2000100;
const ll mod=998244353;
const ll inf=2000000000000000000;
map<int,int>r[2],c[2];
map<pair<int,int>,int>last;
ll pw2[N];
void solve(){
    int n,m,k;cin>>n>>m>>k;
    pw2[0]=1;
    for (int i=1;i<N;i++){
        pw2[i]=(pw2[i-1]*2)%mod;
    }
    int BAD_R=0,BAD_C=0;
    int CNT_R=0,CNT_C=0;
    int bad0=0,bad1=0;
    for (int it=1;it<=k;it++){
        int x,y,t;cin>>x>>y>>t;
        if ((last.find({x,y}))!=last.end()){
            if ((--r[(x+y+last[{x,y}]+1)%2][x])==0 && (r[(x+y+last[{x,y}])%2][x])>0) BAD_R--;
            if ((--c[(x+y+last[{x,y}]+1)%2][y])==0 && (c[(x+y+last[{x,y}])%2][y])>0) BAD_C--;
            if ((r[(x+y+last[{x,y}]+1)%2][x])==0) CNT_R--;
            if ((c[(x+y+last[{x,y}]+1)%2][y])==0) CNT_C--;
            bad0-=(x+y+last[{x,y}]+1)%2;
            bad1-=(x+y+last[{x,y}])%2;
        }
        if (t!=-1){
            if ((++r[(x+y+t+1)%2][x])==1 && (r[(x+y+t)%2][x])>0) BAD_R++;
            if ((++c[(x+y+t+1)%2][y])==1 && (c[(x+y+t)%2][y])>0) BAD_C++;
            if ((r[(x+y+t+1)%2][x])==1) CNT_R++;
            if ((c[(x+y+t+1)%2][y])==1) CNT_C++;
            bad0+=(x+y+t+1)%2;
            bad1+=(x+y+t)%2;
            last[{x,y}]=t;
        } else last.erase({x,y});
//        cout<<BAD_C<<" "<<BAD_R<<" "<<bad0<<" "<<bad1<<endl;
        ll res=0ll;
        if (BAD_R==0) res+=pw2[n-CNT_R];
        if (BAD_C==0) res+=pw2[m-CNT_C];
//        res/=2;
        if (bad0==0) res--;
        if (bad1==0) res--;
        cout<<(res+mod)%mod<<endl;
    }

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

//10
//01
//01
//10
//
//10
//10
//
//01
//01
//
//11
//00
//
//00
//11
/**
2 2 4
1 1 1
1 2 1
2 1 1
1 1 0

**/