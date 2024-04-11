#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
template<class T> T min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
template<class T> T max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}


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
		seg.resize(seg_size*2-1);
		for(int i=0;i<seg_size*2-1;i++) seg[i]=e;
	}
 
	T sum_sub(int a,int b,int l,int r,int k){
		if(r<=a||b<=l) return e;
		if(a<=l&&r<=b) return seg[k];
		T X=sum_sub(a,b,l,(l+r)/2,k*2+1);
		T Y=sum_sub(a,b,(l+r)/2,r,k*2+2);
		return X+Y;
	}
	T sum(int a,int b){
		//assert(0<=a&&b<n);
		return sum_sub(a,b,0,seg_size,0);
	}
	T get(int index){
		assert(0<=index&&index<n);
		return seg[seg_size-1+index];
	}
	void insert(int index,T a){
		assert(0<=index&&index<n);
		int now_index=index+seg_size-1;
		seg[now_index]=a;
		while(now_index!=0){
			now_index-=1;
			now_index/=2;
			seg[now_index]=seg[now_index*2+1]+seg[now_index*2+2];
		}
	}
};

//q0~n
long long inversion_permutation(std::vector<int> &q){
	int n=q.size();
	po167::seg_sum<int> S(n,0);
	long long ans=0;
	for(int i=0;i<n;i++){
		assert(0<=q[i]&&q[i]<n);
		assert(S.get(q[i])==0);
		ans+=S.sum(q[i],n);
		S.insert(q[i],1);
	}
	return ans;
}
template <class T>
//p
//
long long inversion_vector(std::vector<T> &p){
	int n=p.size();
	std::vector<int> q(n);
	for(int i=0;i<n;i++) q[i]=i;
	sort(q.begin(),q.end(),[&](int l,int r){
		if(p[l]==p[r]) return l<r;
		return p[l]<p[r];
	});
	return inversion_permutation(q);
}
 
}
using po167::inversion_permutation;
using po167::inversion_vector;
using po167::seg_sum;
void solve();
// oddloop
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	int N;
	cin>>N;
	vector<ll> A(N);
	rep(i,N) cin>>A[i];
	vector<ll> B(N+1);
	rep(i,N){
		B[i+1]=B[i]+A[i];
	}
	ll ans=inversion_vector(B);
	ll tmp=B[N];
	So(B);
	if(B[0]!=0||tmp!=B[N]) cout<<"-1\n";
	else cout<<ans<<"\n";
}