#include<bits/stdc++.h>
using namespace std;
int read(){
	char c=getchar();
	int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*x;
}
#define int long long
const int N=1e5+55;
int T,n,m;
int gcd(int x,int y){
	if(!x)return y;
	else return gcd(y%x,x);
}
int w[N],tong[30];
int pd[N*30];
signed main(){
	ios::sync_with_stdio(false); 
	cin>>T;
	for(int i=0;i<=20;i++)pd[1<<i]=i;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>w[i];
		for(int i=1;i<=n;i++)tong[pd[w[i]]]++;
		int sy=m,js=0,summ=1;
		while(1){
			for(int k=20;k>=0;k--){
				if(tong[k] and sy>=(1<<k)){
					int zs=0;
					for(int j=1;j<=tong[k];j++){
						if(sy<(1<<k))break;
						sy-=(1<<k);js++;zs++;
					}
					tong[k]-=zs;
				}
			}
			if(js==n)break;
			sy=m;summ++;
		}
		cout<<summ<<endl;
	}
	return 0;
}