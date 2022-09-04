#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
ll int MOD=1e9+7;
#define N 600000
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    int n;
    cin>>n;
    int a[4][3]={},b[4][3]={};
    rep(i,n){
        string s;
        cin>>s;
        int t=s.size();
        if(s[t-1]=='S') a[t-1][0]++;
        else if(s[t-1]=='L') a[t-1][1]++;
        else a[t-1][2]++;
    }
    rep(i,n){
        string s;
        cin>>s;
        int t=s.size();
        if(s[t-1]=='S') b[t-1][0]++;
        else if(s[t-1]=='L') b[t-1][1]++;
        else b[t-1][2]++;
    }
    int sum=0;
    rep(i,4){
        rep(j,3){
            sum+=min(a[i][j],b[i][j]);
        }
    }
    cout<<n-sum;
    return 0;
}