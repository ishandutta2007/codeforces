#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int mod=998244353,i2=(mod+1)>>1;
int n,m,x,y,up;
int sg[100001],f[1<<17];
vector<int>t[100001],v[100001];
bool ok[100001];
inline int add(int x,int y){
	return x+y<mod?x+y:x+y-mod;
}
inline int sub(int x,int y){
	return x<y?x+mod-y:x-y;
}
inline int power(int a,int n){
	int tp=1;
	while(n){
		if(n&1) tp=1ll*tp*a%mod;
		a=1ll*a*a%mod,n>>=1;
	}
	return tp;
}
inline int dfs(int i){
	if(sg[i]!=-1) return sg[i];
	for(int j:t[i]) v[i].push_back(dfs(j));
	for(int j:v[i]) ok[j]=1;
	sg[i]=0;
	while(ok[sg[i]]) sg[i]++;
	f[sg[i]]++;
	for(int j:v[i]) ok[j]=0;
	return sg[i];
}
inline void fwt(int *a,int n){
	for(int len=1,gu=2;len<n;len<<=1,gu<<=1){
		for(int i=0;i<n;i+=gu){
			for(int j=0;j<len;j++){
				x=a[i|j],y=a[i|j|len];
				a[i|j]=add(x,y),a[i|j|len]=sub(x,y);
			}
		}
	}
}
inline void ifwt(int *a,int n){
	for(int len=1,gu=2;len<n;len<<=1,gu<<=1){
		for(int i=0;i<n;i+=gu){
			for(int j=0;j<len;j++){
				x=a[i|j],y=a[i|j|len];
				a[i|j]=1ll*(x+y)*i2%mod,a[i|j|len]=1ll*(x-y+mod)*i2%mod;
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>x>>y,t[x].push_back(y);
	memset(sg,-1,sizeof(sg));
	for(int i=1;i<=n;i++) dfs(i);
	for(int i=0;i<=n;i++) f[i]=mod-1ll*f[i]*power(n+1,mod-2)%mod;
	f[0]++;
	up=1;
	while(up<=n) up<<=1;
	fwt(f,up);
	for(int i=0;i<up;i++) f[i]=power(f[i],mod-2);
	ifwt(f,up);
	cout<<(mod+1-1ll*power(n+1,mod-2)*f[0]%mod)%mod;
}