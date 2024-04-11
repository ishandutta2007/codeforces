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
template<class T> void print(vector<T> &v) {rep(i,v.size()) cout<<v[i]<<endl;}

ll N;
vector<pair<ll,ll>> p;
vector<ll> r;

bool ju(pair<ll,ll> &a){
	if(a.first<a.second) return true;
	else{
		swap(a.second,a.first);
		return false;
	}
}



ll f(ll a){
	vector<pair<ll,ll>> q(2);
	q[0]={0,I};
	q[1]={0,I};
	ll k=-1,rev=0,i=a,tisai=a,J=0;
	pair<ll,ll> x;
	while(i<N&&J==0){
		//cout<<J<<endl;
		if(r[2*N-1-i]==-1){
			i++;
			continue;
		}
		ll j=r[2*N-1-i];
		x=p[j];
		if(i!=a&&q[1].second>2*N-1-i){
			k=i;
			break;
		}
		if(!ju(x)) rev++;
		r[x.second]=-1,r[x.first]=-1;
		ll b=x.first;
		if(b>=N){
			J=1;
			break;
		}
		for(ll l=tisai;l<b;l++){
			j=r[l];
			x=p[j];
			if(ju(x)) rev++;
			if(q[1].second<x.second){
				J=1;
				break;
			}
			r[x.second]=-1,r[x.first]=-1;
			q[1]=x;
		}
		tisai=b+1;
		i++;
	}
	//cout<<k<<" "<<a<<" "<<rev<<" "<<J<<endl;
	if(q[0].first>q[1].second||q[1].first>q[1].second) J=1;
	if(J==1) return Q*2;
	if(k!=-1) return f(k)+min(k-a-rev,rev);
	else return min(N-a-rev,rev);
}

//main
int main() {
	cin>>N;
	r.resize(N*2);
	p.resize(N);
	rep(i,N){
		ll a,b;
		cin>>a>>b;
		a--,b--;
		p[i]={a,b};
		r[a]=i,r[b]=i;
	}
	ll A=f(0);
	if(A>=Q) cout<<"-1"<<endl;
	else cout<<A<<endl;
}