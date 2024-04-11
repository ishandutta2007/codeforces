#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=1e9+7;
#define INF 2*1e9
#define N 210000
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

void ask(int a,int b,int c,int d){
    cout<<'?'<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    return;
}
int check(){
    string t;
    cin>>t;
    if(t=="YES") return 1;
    return 0;
}
main(){
    int n;
    cin>>n;
    vector<char> v;
    pii now={1,1};
    int d=n-1;
    while(d){
        ask(now.first,now.second+1,n,n);
        if(check()){
            now.second++;
            v.pb('R');
            d--;
        }
        else{
            now.first++;
            v.pb('D');d--;
        }
        cout.flush();
    }
    vector<char> w;
    pii nw={n,n};d=n-1;
    while(d){
        ask(1,1,nw.first-1,nw.second);
        if(check()){
            nw.first--;w.pb('D');d--;
        }
        else{
            nw.second--;w.pb('R');d--;
        }
        cout.flush();
    }
    rep(i,w.size()){
        v.pb(w[w.size()-1-i]);
    }
    cout<<'!'<<" ";
    rep(i,v.size()){
        cout<<v[i];
    }
    cout<<endl;
    cout.flush();
    return 0;
}