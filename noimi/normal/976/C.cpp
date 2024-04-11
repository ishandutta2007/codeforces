#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep3(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
#define MAX_V 400010
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
template<typename A, size_t NNN, typename T>
void Fill(A (&array)[NNN], const T &val){
    fill( (T*)array, (T*)(array+NNN), val );
}
#define N 300100
#define INF 1e9+7
ll MOD=1e9+7;

main(){
    int n=in();
    struct seg{
        int first,second,id;
        void print(){
            printf("%d %d %d\n",first,second,id);
        }
    };
    vector<seg> v;
    rep(i,n){
        v.pb(seg{in(),in(),i+1});
    }
    sort(ALL(v),[](seg a,seg b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    });
    int id[N],suf[N];
    suf[n]=INF;
    id[n]=-1;

    rep(i,n){
        if(v[n-i-1].second<suf[n-i]){
            id[n-i-1]=v[n-1-i].id;
            suf[n-1-i]=v[n-i-1].second;
        }
        else{
            id[n-i-1]=id[n-i];
            suf[n-1-i]=suf[n-i];
        }
    }
    rep(i,n){
        int r=v[i].second;
        if(r>=suf[i+1]){
            cout<<id[i+1]<<" "<<v[i].id;
            return 0;
        }
    }
    printf("-1 -1");
}