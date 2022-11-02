#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#include<vector>
#include<ctime>
#include<cmath>
#include<bitset>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
//#define int long long
using namespace std;
typedef long long ll;
int read(){
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
const int N=2e6+5;
const int mod=1e9+7;
int ycl[N],n,a[N],s[N],tong[N],tmp;
int c[2][2],d[2][2];
void change(int f[],int b[2][2]){
	for(int i=1;i<n;i*=2){
		for(int k=0;k<n;k+=i*2){
			for(int j=0;j<i;j++){
				int tmp=f[k+j];
				f[k+j]=((1ll*b[0][0]*f[k+j]%mod+1ll*b[0][1]*f[k+j+i]%mod)%mod+mod)%mod;
				f[k+j+i]=((1ll*b[1][0]*tmp%mod+1ll*b[1][1]*f[k+j+i]%mod)%mod+mod)%mod;
			}
		} 
	}
}
int main(){
	
	n=read();int tmp=n;
	ycl[0]=1;
	for(int i=1;i<=n;i++){
		a[i]=read();tong[a[i]]++;
		ycl[i]=2ll*ycl[i-1]%mod;
		tmp=max(tmp,a[i]);
	}
	c[0][0]=c[0][1]=c[1][1]=1;
	d[0][0]=d[1][1]=1;
	d[0][1]=mod-1;	
	n=1;
	for(;n<=tmp;n=n*2);
	change(tong,c);
	for(int i=0;i<n;i++){
		s[i]=ycl[tong[i]];
	}
	change(s,d);
	cout<<s[0];
	return 0;
}