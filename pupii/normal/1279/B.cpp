#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
ll a[100010],b[100010];
int main(){
	ll T=gi(),n,s;
	while(T--){
		n=gi(),s=gi();
		for(int i=1;i<=n;++i)a[i]=gi();
		for(int i=1;i<=n;++i)b[i]=a[b[i-1]]>a[i]?b[i-1]:i;
		for(int i=1;i<=n;++i)a[i]+=a[i-1];
		int ans1=0;
		for(int i=1;i<=n;++i)if(a[i]-a[b[i]]+a[b[i]-1]<=s)ans1=b[i];
		if(a[n]<=s)ans1=0;
		printf("%d\n",ans1);
	}
	return 0;
}