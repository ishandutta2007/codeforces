#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
const int N=1005;
int n,m;
int f[N],g[N];
int gcd(int x,int y){
	if(!x)return y;
	else return gcd(y%x,x);
}
void clear(){
	cout.flush();
}
int ask(int h,int w,int i1,int j1,int i2,int j2){
	cout<<"? "<<h<<" "<<w<<" "<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<endl;
	clear();
	int x;
	cin>>x;
	return x;
}
int st[N],top;
int queryh(int l,int r){
	if(l==r)return 1;
	int tot=(r-l+1)/2;
	int mid=(l+tot-1);
	if(ask(tot*(st[2]-st[1]),m,st[l],1,st[mid+1],1)){
		return queryh(mid+1,r);
	}
	else return 0;
}
int queryl(int l,int r){
	if(l==r)return 1;
	int tot=(r-l+1)/2;
	int mid=(l+tot-1);
	if(ask(n,tot*(st[2]-st[1]),1,st[l],1,st[mid+1])){
		return queryl(mid+1,r);
	}
	else return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	f[n]=g[m]=1;
	for(int i=n-1;i>=1;i--){
		if(!f[i] and n%i==0){
			if(!f[i]){
				top=0;
				for(int k=i*2;k<=n;k+=i){
					if(n%k==0){
						for(int j=1;j<=k/i;j++){
							st[++top]=(j-1)*i+1;
						}
						break;
					}
				}
				if(queryh(1,top))f[i]=1;
				else f[i]=2;
			}
			if(f[i]==1){
				for(int k=i+1;k<=n;k++){
					if(f[k]==2 || !f[k])continue;
					int g=gcd(i,k);
					for(int j=g;j<=n;j+=g){
						if(n%j==0)f[j]=1;
					}
				}
			}
			if(f[i]==2){
				for(int k=1;k<=i;k++){
					if(i%k==0){
						f[k]=2;
					}
				}
			}
		}
	}
	g[m]=f[n];
	for(int i=m-1;i>=1;i--){
		if(!g[i] and m%i==0){
			if(!g[i]){
				top=0;
				for(int k=i*2;k<=m;k+=i){
					if(m%k==0){
						for(int j=1;j<=k/i;j++){
							st[++top]=(j-1)*i+1;
						}
						break;
					}
				}
				if(queryl(1,top))g[i]=1;
				else g[i]=2;
			}
			if(g[i]==1){
				for(int k=i+1;k<=m;k++){
					if(g[k]==2 || !g[k])continue;
					int G=gcd(i,k);
					for(int j=G;j<=m;j+=G){
						if(m%j==0)g[j]=1;
					}
				}
			}
			if(g[i]==2){
				for(int k=1;k<=i;k++){
					if(i%k==0){
						g[k]=2;
					}
				}
			}
		}
	}
	int ans1=0,ans2=0;
	for(int i=1;i<=n;i++){
		if(f[i]==1)
		{
			ans1++;
		}
	}
	for(int k=1;k<=m;k++){
		if(g[k]==1)
		{
			ans2++;
		}
	}
	cout<<"! "<<ans1*ans2;
	return 0;
}