#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) rep2(i,0,n-1)
int MOD=1000000000+7;
int INF=1e6;
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

int n,m;
int a[200][200]={};
bool check(int x,int y){
    if(a[x][y]==9) return 1;
    int count=0;
    rep2(i,-1,1){
        rep2(j,-1,1){
            if(a[x+i][y+j]==9) count++;
        }
    }
    if(a[x][y]==count) return 1;
    else return 0;
}
main(){
    cin>>n>>m;
    rep(i,n){
        rep(j,m){
            char c;
            cin>>c;
            if(c=='*') a[i][j]=9;
            else if(c=='.') a[i][j]=0;
            else a[i][j]=c-'0';
        }
    }
    rep(i,n){
        rep(j,m){
            if(!check(i,j)){
                cout<<"NO"; return 0;
            }
        }
    }
    cout<<"YES";
    return 0;


}