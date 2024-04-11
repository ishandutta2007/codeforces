#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=1e9+7;
#define INF 1e9+7
#define N 1100000
#define MAX_V 900010
#define vec vector<int>
using namespace std;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define umap unordered_map<ll,int,custom_hash>

int ask(int x,int y){
    printf("%d %d\n",x,y);
    string s;cin>>s;
    fflush(stdout);
    if(s=="black")return 1;
    else return 0;
}
main(){
    int n;cin>>n;
    int c=1;
    int t=ask(10,0);
    int l=0,r=999999998;
    rep(i,n-1){
        int mid=(l+r)/2;
        if(l==mid)break;
        if(ask(10,mid)==t)l=mid;
        else r=mid;
        c++;
    }
    if(c!=n){
        if(ask(11,l)==t){
            printf("%d %d %d %d\n",11,l+1,9,l);
        }
        else{
            printf("%d %d %d %d\n",11,l-1,9,l+2);
        }
    }
    else{
        cout<<11<<" "<<l<<" "<<9<<" "<<r<<endl;
    }
}