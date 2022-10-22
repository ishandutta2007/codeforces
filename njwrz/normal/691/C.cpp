/*

DP





ll int
 dp 










*/
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
char c[1000005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%s",c+1);
	int n=strlen(c+1);
	int l=1,r=n;
	int t=-1;
	FOR(i,1,n){
		if(c[i]=='.')t=i;
	}
	if(t==-1)t=n+1;
	while(c[l]=='0'||c[l]=='.')l++;
	while(c[r]=='0'||c[r]=='.')r--;
	cout<<c[l];
	int to=l+1;
	if(l<r){
		cout<<'.';
		FOR(i,l+1,r){
			if(c[i]!='.')cout<<c[i];
		}
	}
	if(to==t){
		
	}else if(t>to)cout<<'E'<<t-to;
	else cout<<'E'<<t-to+1;
	RE 0;
}