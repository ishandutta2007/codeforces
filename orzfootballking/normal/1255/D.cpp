#pragma GCC optimize("Ofast,unroll-loops")
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
int a[105][105],ans[105][105],l[105];
string s=" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
void solve(){
	int n,m,k,sum=0,co=1;
	cin>>n>>m>>k;
	char c;
	FOR(i,1,n){
		FOR(j,1,m){
			cin>>c;
			if(c=='R')a[i][j]=1,sum++;else a[i][j]=0;
		}
	}
	int mod;
	mod=sum%k;
	FOR(i,1,k-mod)l[i]=l[i-1]+sum/k;
	FOR(i,k-mod+1,k)l[i]=l[i-1]+sum/k+1;
	int x=1,y=1,fx=1;sum=0;
	FOR(i,1,n*m){
		if(sum==l[co]&&a[x][y]){
			co++;
		}
		ans[x][y]=co;sum+=a[x][y];
		if(y==m&&fx==1){
			x++;fx=-1;
		}else if(y==1&&fx==-1){
			x++;fx=1;
		}else y+=fx;
	}
	FOR(i,1,n){
		FOR(j,1,m){
			cout<<s[ans[i][j]];
		}
		cout<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}