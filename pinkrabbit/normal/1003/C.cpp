#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
int n,k;
int s[5001];
double ans=0;
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i)
		s[i]=s[i-1]+read();
	for(int i=1;i<=n;++i){
		for(int j=i+k-1;j<=n;++j){
			int sum=s[j]-s[i-1];
			ans=max(ans,(double)sum/(j-i+1));
		}
	}
	printf("%.15lf",ans);
	return 0;
}