#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
int T,n,m;
const int N=2e5+55;
int a[N]; 
int tong[N];
int main(){
	T=read();
	while(T--){
		n=read();m=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
			a[i]%=m;
			tong[a[i]]++;
		}
		int ans=(tong[0]>=1);
		for(int i=1;i<ceil(m*1.0/2);i++){
			if(tong[i]!=tong[m-i]){
				ans+=((max(tong[i],tong[m-i])-min(tong[i],tong[m-i])-1)+1);
			}
			else if(max(tong[i],tong[m-i])>0){
				ans++;
			}
		}
		//if(m&1){
		//	ans+=(tong[m/2+1]);
		//}
		if(m%2==0){
			ans+=(tong[m/2]>0);
		}
		for(int i=1;i<=n;i++){
			tong[a[i]]=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}