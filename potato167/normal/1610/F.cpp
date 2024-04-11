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



	rep(i,t) solve();
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<set<pair<int,int>>> G(n);
	vector<set<pair<int,int>>> H(n);
	vector<tuple<int,int,int>> edge(m);
	vector<int> ans(m);
	rep(i,m){
		int a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		edge[i]={a,b,c};
		if(c==1) G[a].insert({b,i}),G[b].insert({a,i});
		else H[a].insert({b,i}),H[b].insert({a,i});
	}
	vector<int> s1(n),s2(n);
	vector<vector<int>> X(n);
	vector<vector<int>> Y(n);
	vector<set<pair<int,int>>> A(n);
	int val=0;
	rep(i,n){
		if(G[i].size()%2==0) continue;
		val+=2;
		int ind=i;
		while(G[ind].size()!=0){
			auto tmp=*(G[ind].begin());
			G[ind].erase(tmp);
			G[tmp.first].erase({ind,tmp.second});
			X[i].push_back(tmp.second);
			ind=tmp.first;
		}
		s1[i]=1;
		A[i].insert({ind,1});
		A[ind].insert({i,1});
	}
	rep(i,n){
		if(H[i].size()%2==0) continue;
		int ind=i;
		while(H[ind].size()!=0){
			auto tmp=*(H[ind].begin());
			H[ind].erase(tmp);
			H[tmp.first].erase({ind,tmp.second});
			Y[i].push_back(tmp.second);
			ind=tmp.first;
		}
		s2[i]=1;
		A[i].insert({ind,2});
		A[ind].insert({i,2});
	}
	rep(i,n){
		int ind=i;
		while(H[ind].size()!=0){
			auto tmp=*(H[ind].begin());
			H[ind].erase(tmp);
			H[tmp.first].erase({ind,tmp.second});
			if(get<0>(edge[tmp.second])==ind) ans[tmp.second]=1;
			else ans[tmp.second]=2;
			ind=tmp.first;
		}
	}
	rep(i,n){
		int ind=i;
		while(G[ind].size()!=0){
			auto tmp=*(G[ind].begin());
			G[ind].erase(tmp);
			G[tmp.first].erase({ind,tmp.second});
			if(get<0>(edge[tmp.second])==ind) ans[tmp.second]=1;
			else ans[tmp.second]=2;
			ind=tmp.first;
		}
	}
	rep(i,n){
		int ind=i;
		while(A[ind].size()==1){
			auto tmp=*(A[ind].begin());
			A[ind].erase(tmp);
			A[tmp.first].erase({ind,tmp.second});
			if(tmp.second==1){
				if(s1[ind]) s1[ind]*=-1;
			}
			else{
				if(s2[ind]) s2[ind]*=-1;
			}
			ind=tmp.first;
		}
	}
	rep(i,n){
		int ind=i;
		while(A[ind].size()!=0){
			auto tmp=*(A[ind].begin());
			A[ind].erase(tmp);
			A[tmp.first].erase({ind,tmp.second});
			if(tmp.second==1){
				if(s1[ind]) s1[ind]*=-1;
			}
			else{
				if(s2[ind]) s2[ind]*=-1;
			}
			ind=tmp.first;
		}
	}
	rep(i,n){
		int ind=i;
		for(auto x:X[i]){
			if((get<0>(edge[x])==ind)^(s1[i]==1)) ans[x]=1;
			else ans[x]=2;
			ind^=get<0>(edge[x]);
			ind^=get<1>(edge[x]);
		}
		ind=i;
		for(auto x:Y[i]){
			if((get<0>(edge[x])==ind)^(s2[i]==1)) ans[x]=1;
			else ans[x]=2;
			ind^=get<0>(edge[x]);
			ind^=get<1>(edge[x]);
		}
	}
	cout<<val<<"\n";
	rep(i,m) cout<<ans[i];
	cout<<"\n";
	//rep(i,n) cout<<s1[i]<<" "<<s2[i]<<endl;
}