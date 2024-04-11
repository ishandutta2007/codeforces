#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
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
int n;
int a[100005];
bool f[100005];
char c[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int ans=0;
	FOR(i,1,n){
		cin>>c[i];
		if(c[i]=='G')a[i]=a[i-1]+1;
		ans=max(ans,a[i]);
	}
	for(int i=n-1;i>=1;i--){
		if(a[i]&&a[i+1])a[i]=a[i+1];
	}
	bool ff=0;
	FOR(i,1,n){
		if(c[i]=='G'){
			ff=1;
		}else if(ff){
			FOR(j,i+1,n)f[j]=1;
			break;
		}
	}
	ff=0;
	for(int i=n;i>=1;i--){
		if(c[i]=='G'){
			ff=1;
		}else if(ff){
			FOR(j,1,i-1)f[j]=1;
			break;
		}
	}
	FOR(i,1,n){
		if(c[i]=='S'){
			if(f[i]){
				ans=max(ans,a[i-1]+1+a[i+1]);
			}
			ans=max(ans,a[i-1]+a[i+1]);
		}
	}
	cout<<ans;
	RE 0;
}