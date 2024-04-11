#include<bits/stdc++.h>
using namespace std;
int n,p[1010];
bool vis[1010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",p+i);
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;;j=p[j]){
			if(vis[j]){
				printf("%d ",j);break;
			}
			vis[j]=true;
		}
	}
}