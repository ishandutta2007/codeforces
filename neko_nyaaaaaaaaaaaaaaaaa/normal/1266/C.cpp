#include<bits/stdc++.h>
#define int long long int
#define ull unsigned long long int
#define getFaster ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define rep(i,init,n) for(int i=init;i<n;i++)
#define rev(i,n,init) for(int i=n;i>=init;i--)
#define MAXN 200005
#define MOD 1000000007
#define f first
#define s second
#define endl '\n'
#define pii pair<int,int>
#define precise(i) cout<<fixed<<setprecision(i)
using namespace std;
const double PI = atan(1.0)*4;
const int64_t INF=100000000000000003;
const int32_t LOG=21;
const int BIG=pow(2,20);
int arr[505][505];
int32_t main(){
  	 getFaster;
	 int r,c;
	 cin>>r>>c;
	 if(r==1 && c==1)
	 {
	 	cout<<0<<endl;
	 	return 0;
	 }
	 if(r==1)
	 {
	 	rep(i,1,c+1)
	 	cout<<i+1<<endl;
	 	return 0;
	 }
	 if(c==1)
	 {
	 	rep(i,1,r+1)cout<<i+1<<" ";
	 	cout<<endl;
	 	return 0;
	 }	
	 rep(i,1,r+1)rep(j,1,c+1)
	 {
	 	 int row=i,col=r+j;
	 	 arr[i][j]=row*col;
	 }
	 rep(i,1,r+1)rep(j,1,c+1)
	 {
	 	cout<<arr[i][j]<<" ";
	 }	
     return 0;
}