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
    string s[6];
    int a[6]={};
    int n;
    cin>>n;
    rep(i,n){
        cin>>s[i];
        if(s[i][0]=='p') a[0]=1;
        if(s[i][0]=='g') a[1]=1;
        if(s[i][0]=='b') a[2]=1;
        if(s[i][0]=='o') a[3]=1;
        if(s[i][0]=='r') a[4]=1;
        if(s[i][0]=='y') a[5]=1;
    }
    string ans[6]={"Power","Time","Space","Soul","Reality","Mind"};
    cout<<6-n<<endl;
    rep(i,6){
        if(!a[i]) cout<<ans[i]<<endl;;
    }
    return 0;
}