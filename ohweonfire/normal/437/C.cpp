#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1003];
int ans;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	while(m--){
			   int x,y;
			   scanf("%d%d",&x,&y);
			   ans+=min(a[x-1],a[y-1]);
	}
	printf("%d\n",ans);
	return 0;
}