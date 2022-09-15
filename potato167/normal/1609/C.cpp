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
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

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
    return p;
}
void solve();
auto table=Eratosthenes(1e6+10);
//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;

	cin>>t;

	rep(i,t) solve();
	//rep(i,10) cout<<table[i];
}

void solve(){
	int n,e;
	cin>>n>>e;
	vector<int> p(n);
	rep(i,n){
		cin>>p[i];
	}
	ll ans=0;
	rep(d,e){
		vector<int> ind;
		for(int i=d;i<n;i+=e){
			if(p[i]!=1) ind.push_back(i);
			if(i+e>=n) ind.push_back(i+e);
		}
		for(int i=d;i<n;i+=e){
			int a=LB(ind,i);
			a=ind[a];
			if(a>=n) break;
			if(table[p[a]]) continue;
			int b=UB(ind,a);
			b=ind[b];
			//cout<<a<<" "<<b<<endl;
			ans+=(ll)((b-a)/e);
			if(a==i) ans--;
		}
	}
	cout<<ans<<"\n";
}