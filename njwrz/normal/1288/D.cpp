#pragma GCC optimize(3)
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
int a[300005][10];
int n,m;int f[1000];
P<int,int> ans ;
bool check(int mid){
	FILL(f,0);
	FOR(i,1,n){
		int t=0;
		FOR(j,1,m){
			if(a[i][j]>=mid)t+=(1<<(j-1));
		}
		f[t]=i;
	}
	FOR(i,0,(1<<m)){
		FOR(j,0,(1<<m)){
			bool anf=1;
			FOR(k,0,m-1){
				if(!(i&(1<<k))&&!(j&(1<<k))){
					anf=0;break;
				}
			}
			if(anf&&f[i]&&f[j]){
				ans.F=f[i];ans.S=f[j];return 1;
			}
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n){
		FOR(j,1,m)cin>>a[i][j];
	}
	int l=0,r=2147483647,mid;
	while(r>=l){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans.F<<' '<<ans.S;
	return 0;
}