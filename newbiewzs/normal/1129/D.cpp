#pragma GCC optimize (2)
#pragma G++ optimize (2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#include<math.h>
//#include<unordered_map>
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define ci ios::sync_with_stdio(false)
#define id(u) ((u-1)/B+1)
//#define int long long
char aa;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int read(){
	char c=getchar();
	ll x=1,s=0;
	while(c<'0'||c>'9'){
	   if(c=='-')x=-1;c=getchar();
	}
	while(c>='0'&&c<='9'){
	   s=s*10+c-'0';c=getchar();
	}
	return s*x;
}

const int N=1e5+55;
const int M=1e5+25;
const int B=160;
const int mod=998244353;
int n,m,pre[N],prv[N],add[N],ans[N],g[N],zuo[N],you[N],a[N],f[N/B+5][N],v[N];
void clear(int u){
	for(int i=zuo[u];i<=you[u];i++){
		f[u][v[i]]=0;v[i]+=add[u];
	}
	add[u]=ans[u]=0;
}
void rebuild(int u){
	for(int i=zuo[u];i<=you[u];i++){
		f[u][v[i]]=(f[u][v[i]]+g[i-1])%mod;
		if(v[i]<=m)ans[u]=(ans[u]+g[i-1])%mod;
	}
}
void jia(int u){
	int s=id(u);
	clear(s);
	rebuild(s);
}
char bb;
int main(){
//	cout<<(&aa-&bb)/1024/1024;
//	freopen("data.in","r",stdin);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		if(id(i)!=id(i-1))zuo[id(i)]=i;
		you[id(i)]=i;
	}
	for(int i=1;i<=n;i++)a[i]=read();
	g[0]=1;
	for(int i=1;i<=n;i++){
		int x=pre[a[i]];
		int y=prv[a[i]];
		int l=y+1,r=x;
		int L=id(l),R=id(r);
		if(R>N/B+2){
			while(1);
		}
		if(i>=4){
			new char;
		}
		if(i==6){
			new char;
		}
		v[i]++;
		clear(id(i));
		rebuild(id(i));
	//	jia(i);
		if(l<=r){
			if(L==R){
				clear(L);
				for(int k=l;k<=r;k++)v[k]--;
				rebuild(L);
			}
			else{
				clear(L);
				for(int k=l;k<=you[L];k++){
					v[k]--;
				}
				rebuild(L);
				clear(R);
				for(int k=zuo[R];k<=r;k++){
					v[k]--;
				}
				rebuild(R);
				for(int k=L+1;k<=R-1;k++){
					add[k]--;
					if(m-add[k]>=0 and m-add[k]<=M)ans[k]=(ans[k]+f[k][m-add[k]])%mod;
				}
			}
		}
		l=x+1,r=i-1;
		L=id(l);R=id(r);
		if(l<=r){
			if(L==R){
				clear(L);
				for(int k=l;k<=r;k++)v[k]++;
				rebuild(L);
			}
			else{
				clear(L);
				for(int k=l;k<=you[L];k++){
					v[k]++;
				}
				rebuild(L);
				clear(R);
				for(int k=zuo[R];k<=r;k++){
					v[k]++;
				}
				rebuild(R);
				for(int k=L+1;k<=R-1;k++){
					add[k]++;
					if(m+1-add[k]>=0 and m+1-add[k]<=M)ans[k]=(ans[k]-f[k][m+1-add[k]]+mod)%mod;
				}
			}
		}
		int tmp=0;
		for(int k=1;k<=id(i)-1;k++)tmp=(tmp+ans[k])%mod;
		for(int k=zuo[id(i)];k<=i;k++)if(v[k]<=m)tmp=(tmp+g[k-1])%mod;
		g[i]=tmp;
		prv[a[i]]=pre[a[i]];
		pre[a[i]]=i;
	}
	cout<<g[n];
	return 0;
}