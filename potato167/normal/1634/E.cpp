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
const ll mod=1e9+7;
#define rep(i,a) for (int i=0;i<a;i++)
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
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	int m;
    cin>>m;
    int sum=0;
    vector<vector<int>> p(m);
    vector<vector<int>> ans(m);
    set<int> s;
    rep(i,m){
        int n;
        cin>>n;
        sum+=n;
        p[i].resize(n);
        ans[i].resize(n);
        rep(j,n){
            cin>>p[i][j];
            if(s.count(p[i][j])) s.erase(p[i][j]);
            else s.insert(p[i][j]);
        }
    }
    if(s.size()){
        cout<<"NO\n";
        return ;
    }
    map<int,set<int>> line_s;
    vector<map<int,int>> q(m);
    rep(i,m){
        rep(j,p[i].size()){
            if(q[i].count(p[i][j])){
                ans[i][q[i][p[i][j]]]=1;
                ans[i][j]=-1;
                q[i].erase(p[i][j]);
                sum-=2;
            }else{
                q[i][p[i][j]]=j;
            }
        }
        for(auto x:q[i]){
            line_s[x.first].insert(i);
        }
    }
    int ind=-1;
    while(sum){
        if(ind==-1){
            ind=(*(*line_s.begin()).second.begin());
        }
        //cout<<ind<<endl;
        int val=(*q[ind].begin()).first;
        ans[ind][q[ind][val]]=1;
        q[ind].erase(val);
        line_s[val].erase(ind);
        ind=*(line_s[val].begin());
        //cout<<ind<<endl;
        ans[ind][q[ind][val]]=-1;
        q[ind].erase(val);
        line_s[val].erase(ind);
        if(line_s[val].size()==0) line_s.erase(val);
        if(q[ind].size()==0) ind=-1;
        sum-=2;
    }
    cout<<"YES\n";
    rep(i,m){
        rep(j,ans[i].size()){
            assert(abs(ans[i][j])==1);
            if(ans[i][j]==1) cout<<"L";
            else cout<<"R";
        }
        cout<<"\n";
    }
}