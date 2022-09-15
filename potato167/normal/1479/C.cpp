#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
ll I=1167167167167167167;
ll Q=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end());reverse(v.begin(),v.end());}

int main() {
    ll L,R;
    cin>>L>>R;
    vector<tuple<ll,ll,ll>> ans;
    if(L==R){
        cout<<"YES"<<endl;
        cout<<"2 1"<<endl;
        cout<<"1 2 "<<L<<endl;
        return 0;
    }
    if(L==1){
        ans.push_back({1,32,1});
        L++;
    }
    ll X=R-L+1;
    ll k=0,S=1;
    while(S<X) k++,S*=2;
    for(ll i=10;i<=30;i++){
        for(ll j=i+1;j<=30;j++){
            ans.push_back({i,j,(1<<(30-j))});
        }
        ans.push_back({i,32,1});
    }
    ll T=L-1;
    for(ll i=10;i<=30;i++){
        ll a=30-i;
        if(X&(1<<a)){
            ans.push_back({1,i,T});
            T+=(1<<a);
        }
    }

    cout<<"YES"<<endl;
    cout<<"32 "<<ans.size()<<endl;
    for(auto x:ans){
        ll a,b,c;
        tie(a,b,c)=x;
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
}