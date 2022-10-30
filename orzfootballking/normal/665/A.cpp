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
int a,b,ta,tb; 
signed main(){
	scanf("%d%d%d%d",&a,&ta,&b,&tb);
	int tx,ty;
	scanf("%d:%d",&tx,&ty);
	int ti=(tx-5)*60+ty,l=ti,r=ti+ta,ans=0;
	for(int i=0;i<1140;i+=b){
		int tl=i,tr=i+tb;
		if(min(r,tr)>max(l,tl)){
			ans++;
		}
	}
	cout<<ans;
	RE 0;
}