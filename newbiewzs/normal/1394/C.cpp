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
//#define int long long
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
#define mid ((l+r)>>1)
const int N=3e5+55;
int n,l=0,r=8e5,jl,x[N],y[N];
char c[N*2];
bool check(int u){
	int mau=-1e9,miu=1e9,mav=-1e9,miv=1e9,maw=-1e9,miw=1e9;
	for(int i=1;i<=n;i++){
		mau=max(mau,x[i]-u);
		miu=min(miu,x[i]+u);
		mav=max(mav,y[i]-u);
		miv=min(miv,y[i]+u);
		maw=max(maw,x[i]-y[i]-u);
		miw=min(miw,x[i]-y[i]+u);
	}
	if(miu<mau || miv<mav || miw<maw)return 0;
	int xia=mav+maw,shang=miv+miw;
	if(xia>miu || shang<mau)return 0;
	return 1;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",c+1);
		int l=strlen(c+1);
		for(int k=1;k<=l;k++){
			if(c[k]=='B')x[i]++;
			else y[i]++;
		}
	}
	while(l<=r){
	//	if(l==0 and r==1){
	//		new char;
	//	}
	//	cout<<"se "<<l<<" "<<r<<endl;
		if(check(mid))jl=mid,r=mid-1;
		else l=mid+1;
	}
//	return 0;
	int mau=-1e9,miu=1e9,mav=-1e9,miv=1e9,maw=-1e9,miw=1e9;
	for(int i=1;i<=n;i++){
		mau=max(mau,x[i]-jl);
		miu=min(miu,x[i]+jl);
		mav=max(mav,y[i]-jl);
		miv=min(miv,y[i]+jl);
		maw=max(maw,x[i]-y[i]-jl);
		miw=min(miw,x[i]-y[i]+jl);
	}
	int xia=mav+maw,shang=miv+miw;
	int ansx=min(shang,miu);
	shang=min(shang,miu);
	xia=max(xia,mau);
	int ss=shang-maw;
	int xx=xia-miw;
	xx=max(xx,mav);
	ss=min(ss,miv);
	int ansy=ss;
	cout<<jl<<endl;
	for(int i=1;i<=ansx;i++)printf("B");
	for(int i=1;i<=ansy;i++)printf("N");
	return 0;
}