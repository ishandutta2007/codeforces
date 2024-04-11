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
#define int long long
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
const int N=1e6+55;
int n,a[N],f[N],s[N],minn,bj,r1,r2,r3,d;
signed main(){
	n=read();r1=read();r2=read();r3=read();d=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		s[i]=min(r2,r1*(a[i]+1));
		s[i]+=s[i-1];
	}
	for(int i=1;i<=n;i++)f[i]=1e18;
//	memset(minn,10,sizeof(minn));
	minn=1e18;
	int ans=1e18;
	f[0]=0;//minn[0]=f[0]-s[0]-3*d;
	for(int i=1;i<=n;i++){
		if(i==n){
			f[i]=f[i-1]+a[n]*r1+r3;
		//	f[i]=min(f[i],minn+s[i]+3*d*i+i*r1+d);
			int y=min(r1*a[n]+r3,min(r2+d+d+r1,r1*(a[n]+1)+d+d+r1));
			ans=min(ans,f[n-2]+r1*a[n]+r3+s[n-1]-s[n-2]+d+d+r1);
			ans=min(ans,f[n-2]+min(r2+d+d+r1,r1*(a[n]+1)+d+d+r1)+s[n-1]-s[n-2]+r1+d);
			for(int k=0;k<n-1;k++){
			/*	if(k==2){
					new char;
				}
				ans=min(ans,f[k]+s[n]-s[k]+(n-k)*r1+(n-k-1)*d*2);
				if(ans==32){
					new char;
				}*/
				ans=min(ans,f[k]+y+s[n-1]-s[k]+(n-k-1)*r1+(n-k-1)*2*d);
			}
			continue;
		}
		f[i]=f[i-1]+a[i]*r1+r3+d;
		f[i]=min(f[i],minn+s[i]+3*d*i+i*r1+d);
		minn=min(minn,f[i-1]-s[i-1]-3*(i)*d-(i-1)*r1);
	}
	cout<<min(f[n],ans);
	return 0;
}