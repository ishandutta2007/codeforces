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
const int INF=1000000000;
const ll mod=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}


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
    ll n,k,x;
    cin>>n>>k>>x;
    x--;
    string S;
    cin>>S;
    vector<int> p={-10};
    int ind=0;
    rep(i,n){
        if(S[i]=='a') p.push_back(-1),ind++;
        else if(p[ind]<0) p.push_back(k),ind++;
        else p[ind]+=k;
    }
    string ans="";
    for(int i=(int)(p.size())-1;i>0;i--){
        if(p[i]==-1) ans+='a';
        else{
            ll tmp=x%(p[i]+1);
            x/=(p[i]+1);
            rep(j,tmp) ans+='b';
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<"\n";
}