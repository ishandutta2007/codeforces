#include<cstdio>
int n,a[200001],num[200001],k[200001],tbd[200001],tot=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i), ++num[a[i]];
	for(int i=1;i<=n;++i)
		if(!num[i]) tbd[++tot]=i;
	printf("%d\n",tot);
	int t=1, left=tot;
	for(int i=1;i<=n;++i){
		if(num[a[i]]>1){
//			printf("%d %d %d\n",a[i],tbd[t],k[a[i]]);
			if(a[i]>tbd[t]) num[a[i]]--, a[i]=tbd[t++], --left;
			else if(left==tot-t+1&&k[a[i]]) num[a[i]]--, a[i]=tbd[t++], --left;
			else k[a[i]]=1;
		}
		printf("%d ",a[i]);
	}
	return 0;
}