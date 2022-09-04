#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) rep2(i,0,n-1)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
int MOD=1000000000+7;
int INF=1e6;

using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    int x,y;
    cin>>x>>y;
    if(x==y) { cout<<"="; return 0;}
    if(x==1) { cout<<"<"; return 0;}
    if(y==1) { cout<<">"; return 0;}
    if(x==2){
        if(y==3){ cout<<"<"; return 0;}
        else if(y==4) { cout<<"="; return 0;}
    }
    if(y==2){
        if(x==3){ cout<<">"; return 0;}
        else if(x==4) { cout<<"="; return 0;}
    }
    if(x>y){ cout<<"<"; return 0;}
    cout<<">"; return 0;
}