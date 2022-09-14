//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const ll mod=1000000007;
const int N=1010;
int a[N][N];
int cnt[N][N][2];
int ans=0;
int n,m,q;
void calc(int i,int j){
    if (i<=0 || j<=0 || i>n || j>m) return;
    ans-=cnt[i][j][0]+cnt[i][j][1];
    if (a[i][j]) cnt[i][j][0]=cnt[i][j][1]=0;
    else {
        cnt[i][j][0]=cnt[i-1][j][1]+1;
        cnt[i][j][1]=cnt[i][j-1][0]+1;
    }
    ans+=cnt[i][j][0]+cnt[i][j][1];
}
void solve(){
    cin>>n>>m>>q;

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            calc(i,j);
            ans--;
        }
    }

    for (int it=1;it<=q;it++){
        int x,y;cin>>x>>y;
        ans+=1-a[x][y];
        a[x][y]^=1;
        ans-=1-a[x][y];
        for (int i=0;i<=min(n-x,m-y);i++){
            calc(x+i,y+i);
            calc(x+i+1,y+i);
            calc(x+i,y+i+1);
        }
        cout<<ans<<endl;
    }

}
int32_t  main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}

//a b c
//a (b+c)/2 (b+c)/2
//(2*a+b+c)/4 (2*a+b+c)/4 (b+c)/2
//(2*a+b+c)/4 (2*a+3*b+3*c)/8 (2*a+3*b+3*c)/8
//(6*a+5*b+5*c)/16 (6*a+5*b+5*c)/16
///C=MEX(A)^B + MEX(B)^A
///MEX(C)=MEX(A)^MEX(B)
///A - DONE
//a b c
//a b c d

//0 1 2 3

//0 1 2 3
//0 1 2 3
//
//1+1+1+1+

/**
3 4 1
1 4

**/