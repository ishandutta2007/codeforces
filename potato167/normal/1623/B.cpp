#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=1167167167167167167;
const int INF=2100000000;
const ll mod=998244353;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t=1;
    cin>>t;
	rep(i,t) solve();
}

void solve(){
    int n;
    cin>>n;
    vector<int> l(n),r(n);
    rep(i,n) cin>>l[i]>>r[i],r[i]++;
    vector<int> p(n);
    vector<int> x(n+1);
    queue<int> q;
    rep(i,n){
        p[i]=r[i]-l[i];
        if(p[i]==1) q.push(i);
    }
    while(!q.empty()){
        int ind=q.front();
        q.pop();
        int a;
        for(int i=l[ind];i<r[ind];i++){
            if(x[i]==0){
                x[i]=1;
                a=i;
                break;
            }
        }
        cout<<l[ind]<<" "<<r[ind]-1<<" "<<a<<"\n";
        rep(i,n){
            if(l[i]<=a&&a<r[i]){
                p[i]--;
                if(p[i]==1) q.push(i);
            }
        }
    }
    cout<<"\n";
}