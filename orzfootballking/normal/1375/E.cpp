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
int a[1005],b[1005],id[1005];
bool f[1005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n)cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	FOR(i,1,n){
		FOR(j,1,n){
			if(!f[j]&&b[i]==a[j]){
				id[i]=j;f[j]=1;break;
			}
		}
	}
	V<P<int,int>> v;
	rep(i,1,n){
		rep(j,1,n){
			if(id[j]>id[j+1]){
				v.PB(MP(id[j+1],id[j]));
				swap(id[j],id[j+1]);
			}
		}
	}
	cout<<v.size()<<'\n';
	for(auto u:v){
		cout<<u.F<<' '<<u.S<<'\n';
	}
	RE 0;
}