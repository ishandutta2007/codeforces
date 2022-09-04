#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) rep2(i,0,n-1)
int MOD=1000000000+7;
int INF=1e6;
 
using namespace std;
string alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

main(){
    int n;
    cin>>n;
    char c;
    int a[110];
    rep(i,n){
        cin>>c;
        rep(j,26){
            if(alphabet[j]==c) a[i]=j;
        }
    }
    int b[26][26]={};
    rep(i,n-1){
        b[a[i]][a[i+1]]++;
    }
    int max=0;
    pair<int,int> ans;
    rep(i,26){
        rep(j,26){
            if(max<b[i][j]){
                max=b[i][j];
                ans.first=i;
                ans.second=j;
            } 
        }
    }
    cout<<alphabet[ans.first]<<alphabet[ans.second];
    return 0;
}