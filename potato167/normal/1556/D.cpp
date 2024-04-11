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

void OR(int a,int b){
	cout<<"or "<<a+1<<" "<<b+1<<endl;
}

void AND(int a,int b){
	cout<<"and "<<a+1<<" "<<b+1<<endl;
}



//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,k;
	cin>>n>>k;
	vector<int> p(n-1),q(n-1),ans(n);
	int A=(1<<30)-1,B=0;
	rep(i,n-1){
		OR(i,n-1);
		cin>>p[i];
		A&=p[i];
		AND(i,n-1);
		cin>>q[i];
		B|=q[i];
	}
	int C=A-B;
	int D;
	AND(0,1);
	cin>>D;
	B+=(C^(D&C));
	rep(i,n-1) ans[i]=(B^(p[i]-q[i]));
	ans[n-1]=B;
	So(ans);
	cout<<"finish "<<ans[k-1]<<endl;
}