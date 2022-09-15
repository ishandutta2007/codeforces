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
const ll mod=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}





//a:Nlog(log(N))
vector<long long> Eratosthenes(long long a){
    if(a<2) return {};
    vector<long long> p(a+1),ans;
    p[0]=1,p[1]=1;
    long long k=2;
    while(k*k<=a){
        if(p[k]==0){
            ans.push_back(k);
            for(long long i=2;i*k<=a;i++){
                p[i*k]=1;
            }
        }
        k++;
    }
    while(k<=a){
        if(p[k]==0) ans.push_back(k);
        k++;
    }
    return ans;
}

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m=1e6+10;
	cin>>n;
	vector<ll> a(n+1),b(n+1);
	rep(i,n) cin>>a[i+1];
	rep(i,n) cin>>b[i+1];
	vector<ll> meb(n+1,1);
	auto er=Eratosthenes(n);
	for(auto x:er){
		for(ll i=x;i<=n;i+=x) meb[i]*=-1;
		for(ll i=x*x;i<=n;i+=x*x) meb[i]=0;
	}
	rep(i,n-1) a[i+2]-=b[i+2];
	for(int i=2;i<=n;i++){
		for(int j=i*2;j<=n;j+=i) a[j]-=a[i];
	}
	vector<ll> ans(m);
	vector<ll> add(m);
	for(int i=1;i<=n;i++){
		if(i==1) ans[0]+=a[i];
		else ans[0]+=abs(a[i]+meb[i]*a[1]);
		if(meb[i]==0){
			continue;
		}else if(meb[i]==1){
			add[0]--;
			int x=a[i]+a[1];
			if(i==1) x=a[1];
			if(x<m) add[max(0,x)]+=2;
		}else{
			add[0]--;
			int x=a[1]-a[i];
			if(x<m) add[max(0,x)]+=2;
		}
	}
	rep(i,m-1) ans[i+1]=ans[i]+add[i],add[i+1]+=add[i];
	int q;
	cin>>q;
	rep(i,q){
		int x;
		cin>>x;
		cout<<ans[x]<<"\n";
	}
}