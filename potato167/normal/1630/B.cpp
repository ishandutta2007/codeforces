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
	vector<int> p(n);
	rep(i,n) cin>>p[i];
	vector<int> q(n+1);
	rep(i,n) q[p[i]]++;
	int x=-1,y=INF,r=0,sum=0,c=k+(n-k+1)/2;
	rep(i,n+1){
		int n_x=i;
		while(sum<c&&r!=n+1) sum+=q[r],r++;
		if(sum<c) break;
		if(y-x>r-n_x) y=r,x=n_x;
		sum-=q[i];
	}
	y--;
	cout<<x<<" "<<y<<"\n";
	int tmp=0;
	int front=1;
	int out=1;
	rep(i,n){
		if(x<=p[i]&&p[i]<=y) tmp++;
		else tmp--;
		if(tmp==out){
			if(out==k){
				cout<<front<<" "<<n<<"\n";
				return ;
			}
			cout<<front<<" "<<i+1<<"\n";
			out++;
			front=i+2;
		}
	}
}