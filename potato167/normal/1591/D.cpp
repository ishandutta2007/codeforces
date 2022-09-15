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

//  rainy ~  ~
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
	vector<int> p(n),q(n);
	int J=0;
	rep(i,n){
		cin>>p[i],p[i]-=1;
		J+=q[p[i]];
		q[p[i]]=1;
	}
	yneos(J||inversion(p)%2==0);
}