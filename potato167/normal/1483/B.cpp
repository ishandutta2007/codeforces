#include <bits/stdc++.h>
using namespace std;
using std::cout;
using ll=long long;
using ld=long double;
ll I=1167167167167167167;
ll Q=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end());reverse(v.begin(),v.end());}
template<class T> void print(vector<T> &v) {rep(i,v.size()) cout<<v[i]<<endl;}

//
long long Gcd(long long a,long long b){
	if(b==0) return a;
	else return Gcd(b,a%b);
}

//167
int main(){
    ll T;
    cin>>T;
    rep(l,T){
        ll N;
        cin>>N;
        vector<ll> p(N);
        queue<ll> q;
        rep(i,N) cin>>p[i];
        rep(i,N) if(Gcd(p[i],p[(i+1)%N])==1) q.push(i);
        vector<ll> to(N);
        rep(i,N) to[i]=(i+1)%N;
        vector<ll> ans;
        while(!q.empty()){
            ll a=q.front();
            q.pop();
            ll b=to[a];
            if(b==-1) continue;
            if(Gcd(p[a],p[b])!=1) continue;
            to[a]=to[b];
            to[b]=-1;
            ans.push_back(b);
            q.push(a);
        }
        cout<<ans.size()<<" ";
        rep(i,ans.size()){
            cout<<ans[i]+1;
            if(i!=ans.size()+1) cout<<" ";
        }
        cout<<endl;
    }
}