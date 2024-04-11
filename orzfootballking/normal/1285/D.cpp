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
int a[100005],n,e[30];
int dfs(int p,int l,int r,int s){
	int t=lower_bound(a+1,a+n+1,s+e[p])-a;
	if(t>r){
		if(!p)return 0;
		return dfs(p-1,l,r,s);
	}
	if(t<=l){
		if(!p)return 0;
		return dfs(p-1,l,r,s+e[p]);
	}
	if(!p)return 1;
	return min(dfs(p-1,l,t-1,s),dfs(p-1,t,r,s+e[p]))+e[p];
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    e[0]=1;
    FOR(i,1,29)e[i]=e[i-1]*2;
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	cout<<dfs(29,1,n,0);
	return 0;
}