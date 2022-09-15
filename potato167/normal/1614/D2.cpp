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
#define rep(i,a) for (int i=0;i<a;i++)
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


void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;

	rep(i,t) solve();
}

void solve(){
	ll n,M=2e7+2;
	cin>>n;
	vector<ll> p(M);
	vector<ll> dp(M);
	auto q=Eratosthenes(M);
	int K=q.size();
	rep(i,n){
		ll a;
		cin>>a;
		vector<int> r={1};
		int ind=0,tmp=0,x;
		while(q[ind]*q[ind]<=a){
			tmp=0;
			while(a%q[ind]==0) a/=q[ind],tmp++;
			x=r.size();
			rep(j,x*tmp) r.push_back(r[j]*q[ind]);
			ind++;
		}
		for(auto y:r){
			p[y]++;
			if(a!=1) p[y*a]++;
		}
	}
	ll c=0;
	for(ll i=M-1;i>=1;i--){
		dp[i]=(i*p[i]);
		rep(j,K){
			//c++;
			if(q[j]*i>=M) break;
			chmax(dp[i],dp[q[j]*i]+i*(p[i]-p[q[j]*i]));
		}
		//if(i<9) cout<<i<<" "<<p[i]<<" "<<dp[i]<<endl;
	}
	//cout<<c<<endl;
	cout<<dp[1]<<"\n";
}