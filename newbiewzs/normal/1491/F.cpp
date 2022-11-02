#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[2005],b[2005];
int topa,topb;
int bj[2005],head,ans[2005];
void clear(){
	cout.flush();
}
int ask(){
	printf("? %d %d\n",topa,topb);
	for(int i=1;i<=topa;i++){
		printf("%d ",a[i]);
	}
	puts("");
	for(int i=1;i<=topb;i++){
		printf("%d ",b[i]);
	}
	puts("");
	clear();
	int x;
	scanf("%d",&x);
	return x;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		topa=topb=head=0;
		for(int i=2;i<=n;i++){
			a[++topa]=i-1;
			b[topb=1]=i;
			if(ask()){
				int l=1;int r=i-1;int jl;
				#define mid ((l+r)>>1)
				while(l<=r){
					topa=topb=0;
					for(int k=1;k<=mid;k++)a[++topa]=k;
					b[topb=1]=i;
					if(ask())jl=mid,r=mid-1;
					else l=mid+1;
				}
				bj[jl]=bj[i]=1;
				for(int k=i+1;k<=n;k++)
				{
					a[topa=1]=k;
					if(ask())bj[k]=1;
				}
				for(int k=1;k<=n;k++){
					if(!bj[k])ans[++head]=k;
				}
				printf("! ");
				printf("%d ",head);
				for(int k=1;k<=head;k++){
					printf("%d ",ans[k]);
				}
				puts("");
				clear();
				memset(bj,0,sizeof(bj));
				break;
			}
		}
	}
}