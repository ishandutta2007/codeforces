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
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int n,k,d; 
int a[100005];
int mi[100005],ma[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>d>>k;
	FOR(i,1,n)cin>>a[i];
	int ci,ca;
	ci=ca=0;
	FOR(i,1,n)if(a[i]>k)ma[++ca]=a[i];else mi[++ci]=a[i];
	sort(ma+1,ma+ca+1,greater<int>());
	sort(mi+1,mi+ci+1,greater<int>());
	FOR(i,1,ca)ma[i]+=ma[i-1];
	FOR(i,1,ci)mi[i]+=mi[i-1];
	int maxi=0;
	FOR(i,0,ca){
		int lst=n-max(0ll,(i-1)*(d+1)+1);
		if(lst<0)break;
		gmax(maxi,ma[i]+mi[min(lst,ci)]);
	}
	cout<<maxi;
	RE 0;
}