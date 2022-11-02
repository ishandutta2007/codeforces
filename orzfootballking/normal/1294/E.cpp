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
vector<int> v[200005];
int n,m,f[200005];
int cl(int p){
	FOR(i,0,n)f[i]=0;
	FOR(i,1,n){
		if(v[i][p]%m==p%m){
			int t=v[i][p]/m+(v[i][p]%m!=0);
			if(t>n)continue; 
			if(t<=i){
				f[i-t]++;
			}else{
				f[i+n-t]++;
			}
		}
	}
	int re=2147483647;
	FOR(i,0,n-1){
		re=min(re,i+n-f[i]);
	}
	RE re;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
	cin>>n>>m;
	FOR(i,1,n){
		v[i].PB(0);
		FOR(j,1,m){
			cin>>x;
			v[i].PB(x);
		} 
	}
	int ans=0;
	FOR(i,1,m)ans+=cl(i);
	cout<<ans;
	RE 0;
}