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
int a[maxn],b[maxn],c[maxn];
int n,k;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(15);
	cin>>n>>k;
	rep1(i,n-1){
		int x,y;
		cout<<"and "<<i<<" "<<i+1<<endl;
		cin>>x;
		cout<<"or "<<i<<" "<<i+1<<endl;
		cin>>y;
		a[i]=x+y;
	}
	for (int i=3;i<=n;++i){
		b[i]=a[i-1]-a[i-2];
	}
	for (int i=3;i<=n;++i){
		b[i]=b[i]+b[i-2];
	}
	int u,v;
	cout<<"and "<<1<<" "<<3<<endl;
	cin>>u;
	cout<<"or "<<1<<" "<<3<<endl;
	cin>>v;
	c[1]=(u+v-b[3])/2;
	for (int i=1;i<=n-1;++i){
		c[i+1]=a[i]-c[i];
	}
	sort(c+1,c+n+1);
	cout<<"finish "<<c[k]<<endl;
	return 0;
}