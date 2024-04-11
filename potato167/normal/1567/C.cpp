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
ll mod=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

int f(int a){
    if(a<10) return a+1;
    int b=a%10;
    int ans=0;
    if(true) ans+=(b+1)*f(a/10);
    if(b<9&&a/10-10>=0) ans+=(9-b)*f(a/10-10);
    //cout<<a<<" "<<ans<<endl;
    return ans;
}

int g(int a){
    if(a<10) return a+1;
    if(a<0||a>=19) return 0;
    return 19-a;
}

void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
    cin>>n;
    int M=10;
    vector<int> p(M);
    rep(i,M){
        p[i]=n%10;
        n/=10;
    }
    int ans=0;
    rep(i,1<<(M-2)){
        auto q=p;
        rep(k,M-2){
            if(i&(1<<k)){
                q[k]+=10;
                q[k+2]--;
            }
        }
        int tmp=1;
        int J=2;
        rep(j,M){
            tmp*=g(q[j]);
            if(q[j]<0||q[j]>=10) J=0;
        }
        ans+=tmp-J;
    }
    cout<<ans<<"\n";
}