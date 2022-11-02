#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T,n;
int a[N],b[N];
int main(){
//	freopen("data.in","r",stdin);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]); 
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i]);
		}
		bool flag=0;
		bool fuck=0;
		for(int i=1;i<=n;i++){
			if(a[i]<b[i]){
				puts("NO");
				flag=1;
				break;
			}
			if(a[i] && b[i])fuck=1;
		}
		if(!flag){
			if(!fuck)puts("YES");
			else{
				for(int i=1;i<=n;i++){
					if(a[i] && b[i]){
						flag=1;fuck=1;
						int cha=a[i]-b[i];
						if(cha<0){
							puts("NO");
						}
						else{
							bool bj=0;
							for(int k=1;k<=n;k++){
								if(max(a[k]-cha,0)!=b[k]){
									puts("NO");
									bj=1;
									break;
								}
							}	
							if(!bj)puts("YES");
						}
						break;
					}
				}	
			}
		}
	}
	return 0;
}