#include<bits/stdc++.h>
using namespace std;
int t,n,a[200020],f[200020],b[200020],ans,que[200020];
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		int tail=1,o,p;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++)
		if (!f[a[i]]){
			f[a[i]]=i;
			ans++;
			b[i]=a[i];
		}
		for (int i=1;i<=n;i++)
		if (f[i]==0){
			while (b[tail]) tail++;
			//printf("%d %d\n",i,tail);
			b[tail]=i;
		}
		tail=0;
		for (int i=1;i<=n;i++)
		if (b[i]==i) que[tail++]=i;
		for (int i=0;i<tail;i++) b[que[i]]=que[(i+1)%tail];
		if (tail==1){
			b[que[0]]=a[que[0]];
			b[f[a[que[0]]]]=que[0];
		}
		printf("%d\n",ans);
		for (int i=1;i<=n;i++) printf("%d ",b[i]);
		printf("\n");
		for (int i=1;i<=n;i++) f[i]=b[i]=0;
		ans=0;
	}
}