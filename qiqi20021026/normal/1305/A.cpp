#include<bits/stdc++.h>

using namespace std;

#define N 300

int t,n,a[N],b[N];

int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (int i=1;i<=n;++i) scanf("%d",a+i);
		for (int i=1;i<=n;++i) scanf("%d",b+i);
		sort(a+1,a+n+1); sort(b+1,b+n+1);
		for (int i=1;i<=n;++i) printf(i==n?"%d\n":"%d ",a[i]);
		for (int i=1;i<=n;++i) printf(i==n?"%d\n":"%d ",b[i]);
	}
	
	return 0;
}