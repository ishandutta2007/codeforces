#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,ans;
char a[1000010],b[1000010]; 
int main(){
	scanf("%d",&n);
	scanf("%s",a);
	scanf("%s",b);
	for (int i=0;i<n;i++)
	if (a[i]!=b[i]){
		if (a[i+1]!=b[i+1]&&a[i+1]==b[i]) swap(a[i],a[i+1]);
		ans+=1;
	}
	printf("%d\n",ans);
}