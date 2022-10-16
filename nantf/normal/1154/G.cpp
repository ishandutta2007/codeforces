#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
int n,a[1000100],mn[10001000][2],mx;
int at[10001000],x,y;
ll ans=1e18;
int main(){
	scanf("%d",&n);
	FOR(i,1,n){
		scanf("%d",a+i);
		if(at[a[i]] && a[i]<ans){
			ans=a[i];
			x=at[a[i]];y=i;
		}
		at[a[i]]=i;
		mx=max(mx,a[i]);
	}
	FOR(i,1,mx) FOR(j,1,mx/i){
		if(!at[i*j]) continue;
		if(!mn[i][0]) mn[i][0]=at[i*j];
		else{
			if(i*j<a[mn[i][0]]) mn[i][1]=mn[i][0],mn[i][0]=at[i*j];
			else if(!mn[i][1] || i*j<a[mn[i][1]]) mn[i][1]=at[i*j];
		}
	}
	FOR(i,1,mx) if(mn[i][1] && 1ll*a[mn[i][0]]*a[mn[i][1]]/i<ans)
		ans=1ll*a[mn[i][0]]*a[mn[i][1]]/i,x=mn[i][0],y=mn[i][1];
	printf("%d %d\n",min(x,y),max(x,y));
}
// CDWDDWCDWDDWCDWDDW