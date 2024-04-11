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
void solve(){
	int max1,max2;
	max1=max2=0;
	int n,m,s;
	cin>>s>>n>>m;
	int x;
	FOR(i,1,n){
		cin>>x;
		max1=max(max1,x);
	}
	FOR(i,1,m){
		cin>>x;
		max2=max(max2,x);
	}
	if(max1>max2){
		puts("YES");
	}else puts("NO");
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}