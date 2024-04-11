#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep3(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
ll int MOD=1e9+7;
int INF=1e6;
ll int MAX_N=1e18;
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

       
main(){
    int n=0,m=0;
    int a,b,c,d;
    int s[200][200]={};
    cin>>a>>b>>c>>d;
    cout<<28<<" "<<50<<endl;
    rep(i,28){
        rep(j,50){
            if(i<7) s[i][j]=1;
            else if(i<14) s[i][j]=3;
            else if(i<21) s[i][j]=2;
            else s[i][j]=4;
        }
    }
    rep(i,b-1){
        s[(i/25)*2][(i*2%50)]=2;
    }
    rep(i,d-1){
        s[7+(i/25)*2][(i*2%50)]=4;
    }
    rep(i,a-1){
        s[14+(i/25)*2][(i*2%50)]=1;
    }
    rep(i,c-1){
        s[21+(i/25)*2][(i*2%50)]=3;
    }
    vector<char> v={'.','A','B','C','D'};
    rep(i,28){
        rep(j,50){
            cout<<v[s[i][j]];
        }
        cout<<endl;
    }
    return 0;
}