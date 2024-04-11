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
int n,p[100005],a[100005];
bool dfs(int e){
	if(p[e]!=-1){
		RE p[e];
	}
	for(int i=e+a[e];i<=n;i+=a[e])if(a[i]>a[e]&&!dfs(i))RE p[e]=1;
	for(int i=e-a[e];i>=1;i-=a[e])if(a[i]>a[e]&&!dfs(i))RE p[e]=1;
	RE p[e]=0;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	FILL(p,-1);
	FOR(i,1,n){
		if(dfs(i))cout<<'A';else cout<<'B';
	}
	RE 0;
}