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

void solve(){
	int n;
    cin>>n;
    string S;
    cin>>S;
    vector<int> two,one;
    rep(i,n){
        if(S[i]=='1') one.push_back(i);
        else two.push_back(i);
    }
    if(two.size()!=0&&two.size()<3){
        cout<<"NO\n";
        return ;
    }
    cout<<"YES\n";
    if(two.size()==0){
        rep(i,n){
            rep(j,n){
                if(i==j) cout<<"X";
                else cout<<"=";
            }
            cout<<"\n";
        }
    }
    else{
        set<pair<int,int>> s;
        s.insert({two[two.size()-1],two[0]});
        rep(i,two.size()-1){
            s.insert({two[i],two[i+1]});
        }
        rep(i,n){
            rep(j,n){
                if(i==j) cout<<"X";
                else if(s.count({i,j})) cout<<"+";
                else if(s.count({j,i})) cout<<"-";
                else cout<<"=";
            }
            cout<<"\n";
        }
    }
}



//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	rep(i,t) solve();
}