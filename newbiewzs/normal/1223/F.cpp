#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
//#define int long long
using namespace std;
typedef long long ll;
int read(){
	char c=getchar();int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=3e5+5;
int T,n,a[N],f[N],nxt[N];
map<int,int>ma[N];
int main(){
	T=read();
	while(T--){
		n=read();
		ll ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=n;i>=1;i--){
			if(ma[i+1][a[i]]){
				int tmp=ma[i+1][a[i]];
				swap(ma[tmp+1],ma[i]);
				nxt[i]=tmp;
			}
			ma[i][a[i]]=i;
		}
		for(int i=n;i>=1;i--){
			if(nxt[i])f[i]=f[nxt[i]+1]+1;
			ans=ans+f[i];
		}
		memset(f,0,4*n);
		memset(nxt,0,4*n);
		for(int i=1;i<=n;i++)ma[i].clear();
		cout<<ans<<'\n';
	}
	return 0;
}