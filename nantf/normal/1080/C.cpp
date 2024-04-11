#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		ll bl=1ll*n*m/2,tmp;
		int x[5],y[5];
		for(int i=1;i<=4;i++) scanf("%d%d",y+i,x+i);
		tmp=1ll*(x[2]-x[1]+1)*(y[2]-y[1]+1)/2;
		if((x[1]+y[1])&1) tmp=1ll*(x[2]-x[1]+1)*(y[2]-y[1]+1)-tmp;
		bl-=tmp;
		tmp=1ll*(x[4]-x[3]+1)*(y[4]-y[3]+1)/2;
		if(!((x[3]+y[3])&1)) tmp=1ll*(x[4]-x[3]+1)*(y[4]-y[3]+1)-tmp;
		x[3]=max(x[3],x[1]);x[4]=min(x[4],x[2]);
		y[3]=max(y[3],y[1]);y[4]=min(y[4],y[2]);
		if(x[3]<=x[4] && y[3]<=y[4]){
			ll tmp2=1ll*(x[4]-x[3]+1)*(y[4]-y[3]+1)/2;
			if((x[3]+y[3])&1) tmp2=1ll*(x[4]-x[3]+1)*(y[4]-y[3]+1)-tmp2;
			tmp+=tmp2;
		}
		bl+=tmp;
		printf("%I64d %I64d\n",1ll*n*m-bl,bl);
	}
}