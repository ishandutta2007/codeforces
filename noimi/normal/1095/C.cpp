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
#define N 100010
#define INF 1e15+7
ll MOD=1e9+7;

main(){
    int n=in(),k=in();
    pq p;
    int size=0;
    rep(i,31){
        if(1<<i&n){
            size++;
            p.push(i);
        }
    }
    int v[N];
    v[0]=1;
    rep(i,31){
        v[i+1]=v[i]*2;
    }
    if(size>k||n<k){
        cout<<"NO";return 0;
    }
    else{
        k-=size;
        while(k){
            int temp=p.top();
            p.pop();
            temp--;
            p.push(temp);
            p.push(temp);
            if(temp<0){
                cout<<"NO";return 0;
            }
            k--;
        }
        cout<<"YES\n";
        while(!p.empty()){
            cout<<v[p.top()]<<" ";
            p.pop();
        }
    }
}