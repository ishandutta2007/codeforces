#include<bits/stdc++.h>
#define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int maxn=200007;
const int mod=1e9+7;
const int inf=LLONG_MAX/4;
mt19937 rng(time(NULL)); // don't hack, pls!
int n;
int a,b;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(15);
	int _;
	cin>>_;
	while (_--){
		cin>>a>>b;
		if (a%2!=b%2){
			cout<<-1<<"\n";
			goto cont;
		}
		if (a==b){
			if (a){
				cout<<"1\n";
			}
			else{
				cout<<"0\n";
			}
		}
		else cout<<"2\n";
		cont:;
	}
	return 0;
}