#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=2167167167167167167;
const int INF=2100000000;
const ll mod=998244353;
#define rep(i,a) for (ll i=0;i<a;i++)
#define all(p) p.begin(),p.end()
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}
template<class T> void vec_out(vector<T> &p){for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}


void solve();
// oddloop
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
	string S;
	cin>>S;
	vector<int> p={0};
	vector<int> q={0};
	int ind=0;
	int tmp=0;
	rep(i,n*2){
		if(S[i]=='(') tmp++;
		else tmp--;
		if(p[ind]>=0){
			if(tmp==-1){
				ind++;
				p.push_back(-1);
				q.push_back(-1);
			}else{
				if(chmax(p[ind],tmp)) q[ind]=(i+1);
			}
		}else{
			if(tmp==1){
				ind++;
				p.push_back(1);
				q.push_back(i+1);
			}else if(i==n*2-1){
				ind++;
				p.push_back(0);
				q.push_back(i+1);
			}
		}
	}/*
	cout<<"# ";
	vec_out(p);
	cout<<"# ";
	vec_out(q);*/
	if((int)p.size()==1){
		cout<<"0\n";
		return ;
	}
	int V=0,t=0;
	rep(i,ind){
		if(chmax(V,p[i])) t=q[i];
	}
	if(V<=p[0]+p[ind]){
		cout<<"1\n";
		cout<<q[0]+1<<" "<<q[ind]<<"\n";
	}else{
		cout<<"2\n";
		cout<<"1 "<<t<<"\n";
		cout<<t+1<<" "<<n*2<<"\n";
	}
}