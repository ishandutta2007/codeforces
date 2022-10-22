#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int l[1000005],r[1000005],a[1000005],t[1000005],cnt[1000005];
int n; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int maxi=0;
	cin>>n;
	rep(i,0,n){
		cin>>t[i];
		if(t[maxi]<t[i])maxi=i;
	}
	maxi=n-maxi;
	rep(i,0,n)a[(i+maxi)%n]=t[i];
	a[n]=a[0];
	FOR(i,1,n){
		l[i]=i-1;
		while(l[i]&&a[l[i]]<=a[i]){
			l[i]=l[l[i]];
		}
	}
	for(int i=n-1;i>=0;i--){
		r[i]=i+1;
		while(r[i]<n&&a[r[i]]<a[i]){
			r[i]=r[r[i]];
		}
		if(r[i]<n&&a[r[i]]==a[i]){
			cnt[i]=cnt[r[i]]+1;
			r[i]=r[r[i]];
		}
	}
	int ans=0;
	rep(i,0,n){
		ans+=cnt[i];
		if(a[i]<a[0]){
			ans+=1+(l[i]||r[i]!=n);
		}
	}
	cout<<ans;
	RE 0;
}