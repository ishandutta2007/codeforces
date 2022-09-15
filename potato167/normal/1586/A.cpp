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


//N
vector<long long> Divisors(long long N){
    vector<long long> p,q;
    long long i=1,K=0;
    while(i*i<N){
        if(N%i==0){
            p.push_back(i);
            q.push_back(N/i);
            K++;
        }
        i++;
    }
    if(i*i==N) p.push_back(i);
    for(int i=K-1;i>=0;i--){
        p.push_back(q[i]);
    }
    return p;
}

void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	int sum=0;
	vector<int> p(n);
	rep(i,n){
		cin>>p[i];
		sum+=p[i];
	}
	auto q=Divisors(sum);
	if(q.size()!=2){
		cout<<n<<"\n";
		rep(i,n){
			if(i!=0) cout<<" ";
			cout<<i+1;
		}
		cout<<"\n";
		return ;
	}
	rep(i,n){
		if(p[i]%2==1){
			cout<<n-1<<"\n";
			int J=0;
			rep(j,n){
				if(j==i) continue;
				if(J) cout<<" ";
				J=1;
				cout<<j+1;
			}
			cout<<"\n";
			break;
		}
	}
}