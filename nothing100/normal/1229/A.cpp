#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,b[7070],f[7070];
LL a[7070],ans;
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%lld",&a[i]);
	for (int i=0;i<n;i++) scanf("%d",&b[i]);
	for (int i=0;i<n;i++){
		LL tmp=0;
		int sa=0;
		for (int j=0;j<n;j++) if (a[j]==a[i]) sa++;
		if (sa>1) f[i]=1;
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++)
		if ((a[j]|a[i])==a[j]) f[i]|=f[j];
		if (f[i]) ans+=b[i];
	}
	printf("%lld\n",ans);
}