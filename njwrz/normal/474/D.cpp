#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int a[100005],p[100005];
int mod=1000000007;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int q,k;
	cin>>q>>k;
	int x,y;
	FOR(i,0,k-1)a[i]=1;
	FOR(i,k,100000){
		a[i]=a[i-1]+a[i-k];
		a[i]%=mod;
	}
	FOR(i,1,100000){
		p[i]=p[i-1]+a[i];
		p[i]%=mod;
	}
	FOR(i,1,q){
		cin>>x>>y;
		cout<<(p[y]-p[x-1]+mod)%mod<<'\n';
	}
	return 0;
}