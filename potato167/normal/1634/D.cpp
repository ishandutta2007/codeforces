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

void out(int a,int b,int c){
	cout<<"? "<<a+1<<" "<<b+1<<" "<<c+1<<endl;
}

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
	if(n==4){
		vector<pair<int,int>> p(4);
		rep(i,4) p[i].second=i;
		out(3,1,2);
		cin>>p[0].first;
		out(0,2,3);
		cin>>p[1].first;
		out(0,1,3);
		cin>>p[2].first;
		out(0,1,2);
		cin>>p[3].first;
		So(p);
		cout<<"! "<<p[0].second+1<<" "<<p[1].second+1<<endl;
		return ;
	}
	int ind=2;
	int max_val=-1;
	int J=0;
	int val;
	rep(i,n-2){
		out(0,1,i+2);
		cin>>val;
		if(i==0) max_val=val;
		else if(chmax(max_val,val)) ind=i+2,J=1;
		else if(max_val!=val) J=1;
	}
	int ban=-1;
	int front_max=max_val;
	if(J==0){
		out(2,3,n-1);
		cin>>val;
		if(val>max_val){
			ind=2;
			ban=1;
			J=1;
		}else if(val==0){
			ind=3;
			ban=2;
		}else{
			ind=0;
			ban=n-1;
			J=1;
		}
	}
	int n_ind=(ind+2)%n;
	max_val=-1;
	rep(i,n-2){
		if(ban==(ind+2+i)%n) continue;
		out(ind,(ind+1+i)%n,(ind+2+i)%n);
		cin>>val;
		if(chmax(max_val,val)) n_ind=(ind+2+i)%n;
		else if(i==1&&max_val>val) n_ind=(ind+i)%n;
	}
	if(J==0&&front_max>=max_val) cout<<"! 1 2"<<endl;
	else cout<<"! "<<ind+1<<" "<<n_ind+1<<endl;
}