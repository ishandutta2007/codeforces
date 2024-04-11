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
	int N;
	cin>>N;
	vector<int> zero(N+1),sign(N+1),two(N+1);
	rep(i,N){
		int a;
		cin>>a;
		zero[i+1]=zero[i];
		sign[i+1]=sign[i];
		two[i+1]=two[i];
		if(a==0) zero[i+1]++;
		if(a<0) sign[i+1]^=1;
		if(abs(a)==2) two[i+1]++;
	}
	int ans=0,L=0,R=0;
	int l=0;
	rep(i,N){
		if(zero[i+1]!=zero[i]||i==N-1){
			int h=i;
			if(zero[i+1]==zero[i]) h=i+1;
			vector<int> le(2,INF),ri(2,-1);
			for(int j=l;j<=h;j++){
				if(le[sign[j]]==INF) le[sign[j]]=j;
				else ri[sign[j]]=j;
			}
			//cout<<"#\n";
			//cout<<l<<" "<<h<<"\n";
			rep(k,2){
				//cout<<le[k]<<" "<<ri[k]<<"\n";
				if(ri[k]==-1) continue;
				if(chmax(ans,two[ri[k]]-two[le[k]])){
					L=le[k],R=ri[k];
				}
			}
			l=i+1;
		}
	}/*
	vec_out(two);
	vec_out(sign);
	vec_out(zero);*/
	cout<<L<<" "<<N-R<<"\n";
}