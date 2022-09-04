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
    string s;
    cin>>s;
    vector<string> v={"ABC","ACB","BAC","BCA","CAB","CBA"};
    int m=(s.size()-2);
    rep2(i,1,m){
        string t="AAA";
            t[0]=s[i-1];
            t[1]=s[i];
            t[2]=s[i+1];
        rep(j,6){
            if(t==v[j]) { cout<<"Yes"; return 0;}
        }
    }
    cout<<"No"; return 0;
}