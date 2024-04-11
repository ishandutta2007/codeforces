#include<bits/stdc++.h>
using namespace std;
int t,n,a[200020];
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		int f=0,ansl,ansr,mi,wh;
		for (int i=0;i<n;i++) a[i]=a[i]-i;
		mi=a[0];
		wh=0;
		for (int i=1;i<n;i++)
		if (a[i]>mi){
			f=1;
			ansl=wh;
			ansr=i;
		}
		else{
			mi=a[i];
			wh=i;
		}
		for (int i=0;i<n;i++) a[i]=a[i]+2*i;
		mi=a[n-1];
		wh=n-1;
		for (int i=n-2;i>=0;i--)
		if (a[i]>mi){
			f=1;
			ansr=wh;
			ansl=i;
		}
		else{
			mi=a[i];
			wh=i;
		}
		if (f) printf("YES\n%d %d\n",ansl+1,ansr+1);
		else printf("NO\n");
	}
}