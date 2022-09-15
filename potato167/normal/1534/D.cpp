#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using std::cout;
using std::cin;
using std::endl;
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
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
template<class T> void print_tate(vector<T> &v) {rep(i,v.size()) cout<<v[i]<<"\n";}
void yneos(bool a){if(a) cout<<"Yes"<<"\n"; else cout<<"No"<<"\n";}

vector<pair<int,int>> ans;
int dis[2000];
int N;

void print(int a){
	cout<<"? "<<a+1<<endl;
	rep(i,N) cin>>dis[i];
}

void push(int a){
	rep(i,N){
		if(dis[i]==1) ans.push_back({i+1,a+1});
	}
}

//
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin>>N;
	print(0);
	int A=0,B=0,J=0;
	int p[N];
	rep(i,N){
		p[i]=dis[i];
		if(dis[i]%2==0) A++;
		else B++;
	}
	//cout<<A<<" "<<B<<endl;
	if(A>B) J=1;
	else push(0);
	rep(i,N){
		if(i==0) continue;
		if(p[i]%2==J){
		//	cout<<p[i]<<endl;
			print(i);
			push(i);
		}
	}
	cout<<"!"<<endl;
	rep(i,N-1){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
}