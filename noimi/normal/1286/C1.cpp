
#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <deque>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <chrono>
#include <random>
#include <time.h>
#include <fstream>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pb push_back
#define eb emplace_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vec2 vector<vec>
#define vecll2 vector<vecll>
#define vec3 vector<vec2d>
#define vecll3 vector<vecll2d>
#define fi first
#define se second
#define endl "\n"
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(vector<T> v){for(T e:v)cout<<e<<" ";cout<<endl;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
void print(vector<vec> v){for(auto e:v){for(auto ee:e)cout<<ee<<" ";cout<<endl;}}
void print(map<int,int> mp){for(auto e:mp)cout<<e.first<<" "<<e.second<<endl;cout<<endl;}

void answer(string s){
    int n=s.size();
    rep(i,n){
        rep2(j,1,n-i){
            cout<<s.substr(i,j)<<endl;
        }
    }
}
vector<char> solve(int l,int r){
    int n=r-l+1;
    cout<<"? "<<l<<" "<<r<<endl;
    cout.flush();
    vector<vec> cnt(101,vec(26));
    rep(i,(n+1)*n/2){
        string t;cin>>t;
        int m=t.size();
        for(auto c:t){
            cnt[m][c-'a']++;
        }
    }
    // rep2(i,1,n)print(cnt[i]);
    vector<char> kakutei;
    rep2(i,2,(n+1)/2){
        vec res(26);
        rep(j,26)res[j]+=cnt[1][j]*i;
        rep(j,(i-2)){
            res[kakutei[j*2]-'a']-=(i-1-j);
            res[kakutei[j*2+1]-'a']-=(i-1-j);
        }
        rep(j,26)res[j]-=cnt[i][j];
        rep(j,26)rep(k,res[j])kakutei.pb('a'+j);
    }
    for(auto e:kakutei){
        cnt[1][e-'a']--;
    }
    rep(j,26)rep(k,cnt[1][j])kakutei.pb('a'+j);
    return kakutei;
}
struct edge{
    int a;
    char x,y;
};
vector<char> ans;
vector<int> used;
void dfs(vector<vector<edge>> &G,int x,char c){
    ans[x]=c;
    used[x]=1;
    for(auto e:G[x]){
        if(used[e.a])continue;
        if(c==e.x){
            dfs(G,e.a,e.y);
        }
        else dfs(G,e.a,e.x);
    }
}
main(){
    int n=in();
    if(n==1){
        cout<<"? 1 1\n";cout.flush();
        char c;cin>>c;
        cout<<"! "<<c<<endl;
        return 0;
    }
    // string S;cin>>S;
    vector<vector<edge>> G(n);
    if(n%2){
        // answer(S.substr(0,n-1));cout<<endl;
        // answer(S.substr(1,n-1));cout<<endl;
        vector<char> a=solve(1,n-1),b=solve(2,n);
        // for(auto e:a)cout<<e<<" ";cout<<endl;
        // for(auto e:b)cout<<e<<" ";cout<<endl;
        rep(i,n/2){
            G[i].pb(edge{n-2-i,a[i*2],a[i*2+1]});
            G[n-2-i].pb(edge{i,a[i*2],a[i*2+1]});
        }
        rep2(i,1,n/2){
            G[i].pb(edge{n-i,b[(i-1)*2],b[(i-1)*2+1]});
            G[n-i].pb(edge{i,b[(i-1)*2],b[(i-1)*2+1]});
        }
    }
    else{
        // answer(S.substr(0,n));cout<<endl;
        // answer(S.substr(1,n-1));cout<<endl;
        vector<char> a=solve(1,n),b=solve(2,n);
        rep(i,n/2){
            G[i].pb(edge{n-1-i,a[i*2],a[i*2+1]});
            G[n-1-i].pb(edge{i,a[i*2],a[i*2+1]});
        }
        rep2(i,1,n/2){
            G[i].pb(edge{n-i,b[(i-1)*2],b[(i-1)*2+1]});
            G[n-i].pb(edge{i,b[(i-1)*2],b[(i-1)*2+1]});
        }
    }
    cout<<"? "<<1<<" "<<1<<endl;
    cout.flush();
    char c;cin>>c;
    ans.resize(n);used.resize(n);
    dfs(G,0,c);
    cout<<"! ";
    for(auto e:ans)cout<<e;
    cout<<endl;
}