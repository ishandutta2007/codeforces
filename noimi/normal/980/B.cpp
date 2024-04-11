#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) rep2(i,0,n-1)
int MOD=1000000000+7;
int INF=1e6;
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    int n,k;
    cin>>n>>k;
    int a[n][4]={};
    cout<<"YES"<<endl;
    if(k%2)
    {
        a[n/2][1]=1;
        rep(i,k-1){
            if(i%4==0){
                a[1+i/4][1]=1;
            }
            else if(i%4==1){
                a[n-2-i/4][1]=1;
            }
            else if(i%4==2){
                a[1+i/4][2]=1;
            }
            else if(i%4==3){
                a[n-2-i/4][2]=1;
            }
        }
    }
    else{
        rep(i,k/2){
            a[1+i][2]=a[1+i][1]=1;
        }
    }
    rep(j,4){
        rep(i,n){
            if(a[i][j]) cout<<"#";
            else cout<<".";
        }
        cout<<endl;
    }
    return 0;
}