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
	int n,k;
	cin>>n>>k;
	vector<int> p={};
	int tmp=INF;
	string S;
	cin>>S;
	int score=0;
	rep(i,n){
		if(S[i]=='L') tmp++;
		else if(tmp==0) score+=2;
		else{
			score++;
			p.push_back(tmp);
			tmp=0;
		}
	}
	So(p);
	for(auto x:p){
		if(k>=x){
			k-=x;
			score+=1+2*x;
		}
	}
	if(score==0){
		cout<<max(0,min(n,k)*2-1)<<"\n";
		return ;
	}
	score+=2*k;
	cout<<min(2*n-1,score)<<"\n";
}