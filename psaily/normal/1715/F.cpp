#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--) 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define make_unique(x) { sort(all(x)); x.resize(unique(all(x))-x.begin()); }
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
mt19937 mrand(time(0));
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int mod=998244353;
const ll inf=1ll<<60;
// head
const double eps=1e-12;
const int N=2e5+5;


double query(vector<array<double,2>> p) {
	cout<<"? "<<p.size()<<endl;
	for (auto [x,y]:p) {
		cout<<x<<' '<<y<<endl;
	}
	double S;
	cin>>S;
	return S;
}	

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout<<fixed<<setprecision(12);

   	int n,m;
   	double ansx,ansy;
   	cin>>n>>m;

   	vector<array<double,2>> p;

   	p.push_back({0,(double)m});
   	for (int i=0; i<n; i++) {
   		p.push_back({i+0.,0.});
   		p.push_back({i+1.,m-eps});
   	}
   	p.push_back({(double)n,(double)m});

  	double S=query(p);

  	ansy=(2*S*m-1)*0.5;

  	p={};

  	p.push_back({(double)n,0.});
  	for (int i=0; i<m; i++) {
  		p.push_back({n-eps,(double)i});
  		p.push_back({0.0  ,(double)i+1});
  	}
  	p.push_back({(double)n,(double)m});

  	S=query(p);
  	ansx=(2*S*n-1)*0.5;;

  	cout<<"! "<<ansx<<" "<<ansy<<endl;

	return 0;
}