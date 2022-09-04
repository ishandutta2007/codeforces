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
#define N 200010
#define INF 1e15+7
ll MOD=1e9+7;

main(){
    int n=in();
    int a[N][2];
    rep2(i,1,n){
        a[i][0]=in();a[i][1]=in();
    }
    vec q;
    q.pb(1);
    int temp;
    int t=a[1][0],s=a[1][1];
    if(a[t][0]==s||a[t][1]==s){
        temp=t;q.pb(t);q.pb(s);
    }
    else{
        temp=s;q.pb(s);q.pb(t);
    }
    while(q.size()<n){
        int prepre=q[q.size()-2];
        int pre=q[q.size()-1];
        if(a[prepre][0]==pre){
            q.pb(a[prepre][1]);
        }
        else{
            q.pb(a[prepre][0]);
        }
    }
    rep(i,n)cout<<q[i]<<" ";
}