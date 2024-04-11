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



//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	vector<int> p={2,3,5,7};
	set<int> s;
	rep(i,12){
		rep(j,16){
			if(j==0) continue;
			int X=0;
			rep(k,4){
				if(j&(1<<k)){
					X*=10;
					X+=p[k];
				}
			}
			if(Divisors(X).size()!=2){
				//cout<<X<<endl;
				s.insert(X);
			}
		}
		next_permutation(p.begin(),p.end());
	}
	rep(roop,t){
		int n;
		string S;
		cin>>n>>S;
		vector<int> q;
		set<int> ex;
		int fin=0;
		int ans=INF;
		rep(i,n){
			int a=S[i]-'0';
			if(a!=2&&a!=3&&a!=5&&a!=7){
				cout<<"1\n"<<a<<"\n";
				fin=1;
				break;
			}
			else if(ex.count(a)){
				chmin(ans,a*11);
			}
			else q.push_back(a),ex.insert(a);
		}
		if(fin) continue;
		int M=q.size();
		rep(i,(1<<M)){
			if(i==0) continue;
			int X=0;
			int y=0;
			rep(k,M){
				if(i&(1<<k)){
					X*=10;
					X+=q[k];
				}
			}
			if(s.count(X)){
				chmin(ans,X);
			}
		}
		int D=0,E=ans;
		while(E!=0) E/=10,D++;
		cout<<D<<"\n"<<ans<<"\n";
	}
}