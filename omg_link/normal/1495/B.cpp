#include <stdio.h>
#include <algorithm>
#define MN 100000

int n,a[MN+5];

bool isTop(int x){
	return a[x]>a[x-1]&&a[x]>a[x+1];
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans = 0;
	int maxl = 0;
	int maxc = 1;
	for(int i=1;i<=n;i++){
		if(!isTop(i)) continue;
		int lenl=0,lenr=0;
		for(int j=i-1;j>=1;j--){
			if(a[j]<a[j+1]){
				lenl++;
			}else{
				break;
			}
		}
		for(int j=i+1;j<=n;j++){
			if(a[j]<a[j-1]){
				lenr++;
			}else{
				break;
			}
		}
		if(std::max(lenl,lenr)>maxl){
			maxl = std::max(lenl,lenr);
			maxc = 1;
		}else if(std::max(lenl,lenr)==maxl){
			maxc++;
		}
	}
	for(int i=2;i<=n-1;i++){
		if(!isTop(i)) continue;
		int lenl=0,lenr=0;
		for(int j=i-1;j>=1;j--){
			if(a[j]<a[j+1]){
				lenl++;
			}else{
				break;
			}
		}
		for(int j=i+1;j<=n;j++){
			if(a[j]<a[j-1]){
				lenr++;
			}else{
				break;
			}
		}
		if(lenl!=lenr) continue;
		if(lenl&1) continue;
		if(lenl<maxl||maxc>1) continue;
		ans++;
	}
	printf("%d\n",ans);
}