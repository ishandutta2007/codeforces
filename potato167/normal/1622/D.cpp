#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=1167167167167167;
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


namespace po167{
struct combination{
	std::vector<long long> fact;
	std::vector<long long> rev;
	std::vector<long long> fact_rev;
	long long MOD;
	combination(int max,long long mod):MOD(mod),fact(max+1),rev(max+1),fact_rev(max+1){
		for(long long i=0;i<=max;i++){
			if(i<2){
				fact[i]=1;
				fact_rev[i]=1;
				rev[i]=1;
				continue;
			}
			fact[i]=(fact[i-1]*i)%mod;
			rev[i]=mod-((mod/i)*rev[mod%i])%mod;
			fact_rev[i]=(fact_rev[i-1]*rev[i])%mod;
		}
	}
	long long Comb(int x,int y){
		if (x<y||y<0||x<0) return 0;
		return (((fact_rev[y]*fact_rev[x-y])%MOD)*fact[x])%MOD;
	}
};
}
using po167::combination;

void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t=1;
    //cin>>t;
	rep(i,t) solve();
}

void solve(){
    ll n,K;
    cin>>n>>K;
    string S;
    cin>>S;
    vector<int> p(n);
    int sum=0;
    rep(i,n) p[i]=S[i]-'0',sum+=p[i];
    if(sum<K){
        cout<<"1\n";
        return ;
    }
    combination table(n+100,mod);
    ll ans=1;
    rep(i,n){
        int a=0,b=0;
        for(int j=i;j<n;j++){
            if(a==K&&p[j]==1) break;
            if(p[j]) a++;
            else b++;
        }
        if(a==0||b==0) continue;
        if(p[i]) b--;
        else a--;
        ans+=table.Comb(a+b,a);
    }
    cout<<ans%mod<<"\n";
}