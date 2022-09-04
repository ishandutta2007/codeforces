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
ll MOD=1e9+7;
#define INF 1e9+7
#define N 201000
#define MAX_V 400010
#define vec vector<int>
#define ALL(c) (c).begin(),(c).end()

int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
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
struct pair_hash
{
    template<class T1,class T2>
    size_t operator() (const pair<T1,T2> &p)const{
        return hash<T1>()(p.first)^hash<T2>()(p.second);
    }
};


main(){
    int n=in();
    int a[N];
    int sum=0;
    int count=0;
    rep(i,n){
        a[i]=in();
        sum+=a[i];
        if(a[i]>1)count++;
    }
    if(sum<2*n-2){cout<<"NO";return 0;}
    cout<<"YES"<<" "<<min(count+1,n-1)<<endl;
    cout<<n-1<<endl;
    int pre=-1;
    vector<int> ones;
    rep(i,n){
        if(a[i]==1){
            ones.pb(i);
            a[i]--;
        }
    }
    rep(i,n){
        if(a[i]>1&&pre==-1){
            pre=i;
        }
        else if(a[i]>1){
            a[pre]--;
            printf("%d %d\n",pre+1,i+1);
            pre=i;
            a[pre]--;
        }
    }
    int pos=0,now=0;
    if(ones.size()==0)return 0;
    printf("%d %d\n",pre+1,ones[now]+1);
    a[pre]--;
    now=1;
    while(now<ones.size()){
        while(now<ones.size()&&a[pos]){
            printf("%d %d\n",ones[now]+1,pos+1);
            now++;
            a[pos]--;
        }
        pos++;
    }
}