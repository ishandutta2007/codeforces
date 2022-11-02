#include<bits/stdc++.h> 
using namespace std;
int a,b,c,n; 
int main(){
	scanf("%d%d%d",&a,&b,&c);
	scanf("%d",&n);
	int ans=0;
	for (int i=0;i<n;i++){
		int o;
		scanf("%d",&o);
		if (o>b&&o<c) ans++;
	}
	printf("%d\n",ans);
}