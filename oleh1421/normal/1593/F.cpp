//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=41;
pair<pair<int,int>,pair<int,int> >pr[N][N][N][N];

void solve(){
    int n,A,B;cin>>n>>A>>B;
    string x;cin>>x;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            for (int a=0;a<A;a++){
                for (int b=0;b<B;b++){
                    pr[i][j][a][b]={{-1,-1},{-1,-1}};
                }
            }
        }
    }
    pr[0][0][0][0]={{0,0},{0,0}};
    for (int i=0;i<n;i++){
        for (int j=0;j<=i;j++){
            for (int a=0;a<A;a++){
                for (int b=0;b<B;b++){
                    if (pr[i][j][a][b].second.second==-1) continue;
//                    if (i+j+a+b==0) cout<<(a*10+(x[i-1]-'0'))%A<<endl;
                    pr[i+1][j][(a*10+(x[i]-'0'))%A][b]={{i,j},{a,b}};
                    pr[i+1][j+1][a][(b*10+(x[i]-'0'))%B]={{i,j},{a,b}};
                }
            }
        }
    }
    int best=0;
    for (int i=1;i<n;i++){
        if (pr[n][i][0][0].second.second==-1) continue;
        if (abs(n-2*best)>=abs(n-2*i)) best=i;
    }
    if (best==0) cout<<"-1\n";
    else {
        int a=0,b=0;
        int j=best;
        string ans="";
        for (int i=n;i>=1;i--){
            int nxtj=pr[i][j][a][b].first.second;
            int nxta=pr[i][j][a][b].second.first;
            int nxtb=pr[i][j][a][b].second.second;
            if (nxtj==j) ans+="R";
            else ans+="B";
            j=nxtj;
            a=nxta;
            b=nxtb;
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
}
int32_t  main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
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
1 3
0.0 0.1 0.5 0.2
**/