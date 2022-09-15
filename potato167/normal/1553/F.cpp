#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll I=1167167167167167167;
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


namespace po167{
template <class T>
struct seg_sum{
	int n;
	int seg_size;
	std::vector<T> seg;
	T e;
	// type+
	seg_sum(int k,T e_in){
		e=e_in;
		n=k;
		seg_size=1;
		while(seg_size<n) seg_size*=2;
		seg.resize(seg_size*2);
		for(int i=0;i<seg_size*2;i++) seg[i]=e;
	}
	T sum(int l,int r){
		T l_val=e;
		T r_val=e;
		l+=seg_size;
		r+=seg_size;
		while(l<r){
			if(l&1) l_val=(l_val+seg[l]),l++;
			if(r&1) r--,r_val=(seg[r]+r_val);
			r>>=1;
			l>>=1;
		}
		return l_val+r_val;
	}
	T get(int index){
		assert(0<=index&&index<n);
		return seg[seg_size+index];
	}
	void insert(int index,T a){
		assert(0<=index&&index<n);
		int now_index=index+seg_size;
		seg[now_index]=a;
		while(now_index!=0){
			now_index>>=1;
			seg[now_index]=seg[now_index*2]+seg[now_index*2+1];
		}
	}
};
 
 
template <class T>
//p,q
long long inversion(std::vector<T> &p,std::vector<T> &q){
	int n=p.size();
	assert(p.size()==q.size());
	po167::seg_sum<int> S(n,0);
	std::vector<int> p_index(n,-1);
	std::map<T,std::queue<int>> m;
	for(int i=0;i<n;i++) m[p[i]].push(i);
	for(int i=0;i<n;i++){
		if(m[q[i]].empty()) return -1;
		int a=m[q[i]].front();
		m[q[i]].pop();
		p_index[i]=a;
	}
	long long ans=0;
	for(int i=0;i<n;i++){
		ans+=S.sum(p_index[i],n);
		S.insert(p_index[i],1);
	}
	return ans;
}
 
template <class T>
//q0~n
long long inversion(std::vector<T> &q){
	int n=q.size();
	po167::seg_sum<int> S(n,0);
	std::vector<int> p_index(n);
	for(int i=0;i<n;i++){
		p_index[i]=i;
	}
	long long ans=0;
	for(int i=0;i<n;i++){
		assert(0<=q[i]&&q[i]<n);
		assert(S.get(q[i])==0);
		ans+=S.sum(q[i],n);
		S.insert(q[i],1);
	}
	return ans;
}
}
using po167::inversion;
using po167::seg_sum;


void solve();

//
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T=1;
	rep(i,T) solve();
}

void solve(){
	int n;
	ll M=3*(1e5)+5;
	cin>>n;
	seg_sum<ll> A(M,0);
	seg_sum<ll> B(M,0);
	vector<ll> p(n);
	rep(i,n) cin>>p[i];
	vector<ll> ans(n);
	ll now=0;
	ll sum=0;
	rep(i,n){
		//cul
		now+=sum+i*p[i];
		//cout<<now<<endl;
		now-=A.sum(0,p[i]+1);
		//cout<<now<<endl<<endl;
		ll k=1;
		for(ll j=p[i];j<M;j+=p[i]){
			ll r=min(M,p[i]+j);
			now-=p[i]*B.sum(j,r)*k;
			k++;
		}
		//set
		ans[i]=now;
		B.insert(p[i],1);
		sum+=p[i];
		for(ll j=p[i];j<M;j+=p[i]){
			A.insert(j,A.get(j)+p[i]);
		}
	}
	rep(i,n){
		if(i!=0) cout<<" ";
		cout<<ans[i];
	}
	cout<<"\n";
}