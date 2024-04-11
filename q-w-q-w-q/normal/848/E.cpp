#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=998244353;
int n;
const int a[16]={0,0,0,24,4,240,204,1316,2988,6720,26200,50248,174280,436904,1140888,3436404};
const int g[16]={0,4,8,mod-1,16,mod-10,4,mod-12,mod-48,26,mod-44,15,mod-16,mod-4,mod-4,mod-1};
int f[50001];
inline int add(int x,int y){
	return x+y<mod?x+y:x+y-mod;
}
int main(){
	cin>>n;
	memcpy(f,a,sizeof(a));
	for(int i=16;i<=n;i++)
		for(int j=0;j<16;j++)
			f[i]=(f[i]+1ll*f[i-j-1]*g[j])%mod;
	cout<<f[n];
}