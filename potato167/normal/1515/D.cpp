#include <bits/stdc++.h>
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
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end());reverse(v.begin(),v.end());}
template<class T> void print_tate(vector<T> &v) {rep(i,v.size()) cout<<v[i]<<"\n";}
void yneos(bool a){if(a) cout<<"Yes"<<"\n"; else cout<<"No"<<"\n";}

void solve(){
	int N,L,R;
	cin>>N>>L>>R;
	int p[N],q[N];
	rep(i,N) p[i]=0,q[i]=0;
	rep(i,N){
		int a;
		cin>>a;
		a--;
		if(i<L) p[a]++;
		else q[a]++;
	}
	rep(i,N){
		int a=min(p[i],q[i]);
		p[i]-=a,q[i]-=a,L-=a,R-=a;
	}
	int X=min(L,R),Y=max(L,R);
	int C=0;
	if(L<R){
		rep(i,N) C+=q[i]/2;
	}
	else if(R<L){
		rep(i,N) C+=p[i]/2;
	}
	cout<<Y-min(C,(Y-X)/2)<<"\n";
}

//main
int main() {
	int T;
	cin>>T;
	rep(i,T) solve();
}