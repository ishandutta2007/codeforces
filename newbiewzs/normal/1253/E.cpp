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
#define da(x) cout<<"sese:"<<x<<endl;
#define db(x,y) cout<<"???"<<x<<" "<<y<<endl;
#define dc(x,y,z) cout<<"!!!!:"<<x<<" "<<y<<" "<<z<<endl;
#define dd(x,y,z,w) cout<<"yiw:"<<x<<" "<<y<<" "<<z<<" "<<w<<endl;
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
const int N=85;
const int M=1e6+55;
int n,m,s[M],x[M],y[M];
int f[M];
#define mid ((l+r)>>1)
#define ls (u<<1)
#define rs (u<<1|1)
int minn[M*4];
void add(int u,int l,int r,int x,int k){
	if(l==r){
		minn[u]=k;
		return ;
	}
	if(x<=mid)add(ls,l,mid,x,k);
	else add(rs,mid+1,r,x,k);
	minn[u]=min(minn[ls],minn[rs]);
}
int query(int u,int l,int r,int L,int R){
	if(L<=l and R>=r){
		return minn[u];
	}
	int tmp=1e9+77;
	if(L<=mid)tmp=query(ls,l,mid,L,R);
	if(R>mid)tmp=min(tmp,query(rs,mid+1,r,L,R));
	return tmp;
}
int main(){
	n=read();m=read();
	memset(minn,10,sizeof(minn));
	for(int i=1;i<=n;i++){
		x[i]=read();y[i]=read();
		s[x[i]]++;s[x[i]+y[i]+1]--;
	}
	memset(f,10,sizeof(f));
	f[0]=0;
	add(1,0,m,0,0);
	for(int i=1;i<=m;i++){
		if(i==85){
			new char;
		}
		s[i]+=s[i-1];
		if(s[i])f[i]=min(f[i],f[i-1]);
		f[i]=min(f[i],i);
		for(int k=1;k<=n;k++){
			if(x[k]+y[k]>=i){
				int LL=max(0,x[k]-y[k]-1);
				int RR=i;
				int tmp=query(1,0,m,LL,RR);
				f[i]=min(f[i],tmp);
			}
			else{
				int jl=i-x[k];
				int LL=max(0,x[k]-jl-1);
				int RR=i;
				int tmp=query(1,0,m,LL,RR);
				f[i]=min(f[i],tmp+jl-y[k]);
			}
		}
		add(1,0,m,i,f[i]);
	}
	cout<<f[m];
	return 0;
}