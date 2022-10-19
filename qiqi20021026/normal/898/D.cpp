#include<bits/stdc++.h>

using namespace std;

int n,m,p,ans,a[300000],q[300000];

int main(){
	scanf("%d%d%d",&n,&m,&p);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int tt=1,ww=0;
	for (int i=1;i<=n;i++){
		while (tt<=ww && a[i]-q[tt]+1>m) tt++;
		if (ww-tt+2>=p) ans++; else q[++ww]=a[i];
	}
	printf("%d\n",ans);
	
	return 0;
}