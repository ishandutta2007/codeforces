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
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	ll sum=0;
	vector<ll> p(n);
	rep(i,n) cin>>p[i],sum+=p[i];
	stack<int> s;
	rep(i,n){
		if(i==0) continue;
		while(!s.empty()){
			int a=s.top();
			s.pop();
			if(p[i]-p[i-1]>=i-a+1){
				p[i]-=(i-a);
				p[i-1]+=1;
			}else{
				s.push(a+p[i]-p[i-1]-1);
				p[i]=p[i-1]+1;
				break;
			}
		}
		ll b=(p[i]-p[i-1])/(i+1);
		p[i]-=(i*b);
		p[i-1]+=b;
		if(p[i]==p[i-1]) s.push(i);
		else if(p[i]==p[i-1]+1) continue;
		else{
			s.push(p[i]-p[i-1]-1);
			p[i]=p[i-1]+1;
		}
	}
	vector<ll> q(n,1);
	q[0]=0;
	while(!s.empty()) q[s.top()]=0,s.pop();
	ll add=0;
	rep(i,n-1) q[i+1]+=q[i],add+=q[i+1];
	ll base=(sum-add)/n;
	rep(i,n){
		if(i) cout<<" ";
		cout<<base+q[i];
	}
	cout<<"\n";
}