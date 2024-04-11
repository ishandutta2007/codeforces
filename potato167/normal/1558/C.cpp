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
ll mod=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

void re(vector<int> &p,int a){
	a--;
	rep(i,a/2){
		swap(p[i],p[a-i]);
	}
}

void solve(){
	int n;
	cin>>n;
	vector<int> p(n);
	rep(i,n){
		cin>>p[i];
	}
	rep(i,n){
		if(p[i]%2==i%2){
			cout<<"-1\n";
			return ;
		}
	}
	vector<int> ans((n/2)*5);
	int ind=0;
	for(int i=n;i>1;i-=2){
		int x,y;
		rep(j,n){
			if(p[j]==i){
				x=j;
				break;
			}
		}
		ans[ind]=x+1;
		re(p,x+1);
		rep(j,n){
			if(p[j]==i-1){
				y=j;
				break;
			}
		}
		ans[ind+1]=y;
		re(p,y);
		ans[ind+2]=(y+2);
		re(p,y+2);
		ans[ind+3]=(3);
		swap(p[0],p[2]);
		ans[ind+4]=(i);
		re(p,i);
		ind+=5;
	}
	cout<<ans.size()<<"\n";
	rep(i,ans.size()){
	if(i!=0) cout<<" ";
	cout<<ans[i];
	}
	cout<<"\n";
	return ;
}

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	rep(i,t) solve();
}