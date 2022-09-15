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
#define rep(i,a) for (int i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
template<class T> void print_tate(vector<T> &v) {rep(i,v.size()) cout<<v[i]<<"\n";}
void yneos(bool a){if(a) cout<<"Yes"<<"\n"; else cout<<"No"<<"\n";}

string str(int a){
	string T;
	while(a!=0){
		T+=(char)('0'+a%10);
		a/=10;
	}
	reverse(T.begin(),T.end());
	return T;
}

//
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,k;
	cin>>n>>k;
	if(n%2==1&&k%2==0){
		cout<<"-1"<<endl;
		return 0;
	}
	int ans=0;
	priority_queue<pair<int,int>> pq;
	int sum=n;
	int r[n];
	int X=1;
	int s=1;
	if(k%2==1) s=2;
	if(k%2!=n%2) X++;
	int a,b;
	//cout<<X<<endl;
	while(true){
		int C=X*k;
		a=(C+n-1)/n;
		if(a%2==0) a++;
		if(n<=C&&a<=X){
			//cout<<C<<endl;
			b=(C-(a-2)*n)/2;
			break;
		}
		X+=s;
	}
	//cout<<a<<" "<<b<<endl;
	rep(i,n){
		if(i<b) pq.push({a,i+1});
		else pq.push({a-2,i+1});
	}
	vector<pair<int,int>> p(k);
	while(!pq.empty()){
		cout<<"?";
		rep(i,k){
			cout<<" ";
			p[i]=pq.top();
			pq.pop();
			p[i].first--;
			cout<<p[i].second;
		}
		cout<<endl;
		int a;
		cin>>a;
		ans^=a;
		rep(i,k) if(p[i].first!=0) pq.push(p[i]);
	}
	cout<<"! "<<ans<<endl;
	return 0;
}