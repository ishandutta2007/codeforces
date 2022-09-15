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

void f(vector<int> &p,int k){
	rep(i,k){
		cout<<p[i];
		if(i!=k-1) cout<<".";
		else cout<<"\n";
	}
}

void solve(){
	int N;
	cin>>N;
	vector<int> p(N);
	int k=0;
	rep(i,N){
		int a;
		cin>>a;
		if(a==1){
			p[k]=1;
			k++;
		}
		else{
			k--;
			while(k!=0){
				if(p[k]==a-1){
					p[k]++;
					k++;
					break;
				}
				p[k]=0;
				k--;
			}
			if(k==0) p[k]=a,k++;
		}
		f(p,k);
	}
}

//
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	rep(i,T) solve();
}