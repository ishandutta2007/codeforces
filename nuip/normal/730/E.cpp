#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

const ll MOD = 1e9+7;

int main(){
	int n;
	cin>>n;
	vector<int> a(n),d(n);
	rep(i,n) cin>>a[i]>>d[i];
	//rep(i,n) cin>>d[i];
	vector<int> inc,dec;
	rep(i,n) (d[i]>0?inc:dec).eb(i);
	sort(all(inc),[&](int i,int j){return pii(a[i],-i)<pii(a[j],-j);}); 
	sort(rall(dec),[&](int i,int j){return pii(a[i],-i)<pii(a[j],-j);}); 
	vector<int> ord=inc;
	for(int p:dec) ord.pb(p);
	int re=0;
	for(int i:ord){//cout<<i<<endl;
		rep(j,n) if(i!=j && (pii(a[i],-i)<pii(a[j],-j)) != (pii(a[i]+d[i],-i)<pii(a[j],-j))){
			++re;
			//cout<<i<<","<<j<<endl;
			//cout<<a[i]<<";"<<a[j]<<endl;
		}
		a[i]+=d[i];
	}
	cout<<re<<endl;
	return 0;
}