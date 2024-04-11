#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int a[1000005],b[1000005],n;
int l[1000005],r[1000005];
void solve(){
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	rep(i,1,n)cin>>b[i+1];cin>>b[1];
	FOR(i,1,n){
		int lst=i==1?n:i-1;
		if(a[lst]<=b[i]){
			l[i]=max(a[lst],0);r[i]=b[i]-l[i];
			gmin(a[lst],0);
			a[i]-=r[i];
		}else{
			a[lst]-=b[i];
			l[i]=b[i];
			r[i]=0;
		}
	}
	if(a[n]>0){
		cout<<"NO\n";RE;
	}
	FOR(i,1,n){
		int lst=i==1?n:i-1,t=min(-a[lst],l[i]);
		a[lst]+=t;a[i]-=t;
		l[i]-=t;
		r[i]+=t;
		if(a[i]>0){
			cout<<"NO\n";RE;
		}
	}
	cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}