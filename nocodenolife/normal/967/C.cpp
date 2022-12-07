#include<bits/stdc++.h>
using namespace std;

int n,m,v,q,a[120000],b[120000];

int main(){
	scanf("%*d%*d%d%d%d",&n,&m,&v);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=m;i++)scanf("%d",b+i);
	scanf("%d",&q);
	while(q--){
		int x_1,x_2,y_1,y_2;
		scanf("%d%d%d%d",&y_1,&x_1,&y_2,&x_2);
		if(y_1==y_2)printf("%d\n",abs(x_1-x_2));
		else{
			int ans=INT_MAX;
			int u=lower_bound(a+1,a+n+1,x_1)-a;
			if(u<=n)ans=min(ans,abs(a[u]-x_1)+abs(a[u]-x_2)+abs(y_1-y_2));
			if(u>1)ans=min(ans,abs(a[u-1]-x_1)+abs(a[u-1]-x_2)+abs(y_1-y_2));
			u=lower_bound(b+1,b+m+1,x_1)-b;
			if(u<=m)ans=min(ans,abs(b[u]-x_1)+abs(b[u]-x_2)+(abs(y_1-y_2)+v-1)/v);
			if(u>1)ans=min(ans,abs(b[u-1]-x_1)+abs(b[u-1]-x_2)+(abs(y_1-y_2)+v-1)/v);
			printf("%d\n",ans);
		}
	}
	return 0;
}