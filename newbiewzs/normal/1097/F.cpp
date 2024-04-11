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
const int N=1e5+55;
const int M=7005;
bitset<M>f[N],g[M],p[M],tmp;
int n,m,op,x,y,z,top,vis[N],st[N],miu[M];
int main(){
	n=read();m=read();
	miu[1]=1;
	for(int i=2;i<=7000;i++){
		if(!vis[i])st[++top]=i,miu[i]=-1;
		for(int k=1;i*st[k]<=7000 && k<=top;k++){
			vis[i*st[k]]=1;
			miu[i*st[k]]=-miu[i];
			if(i%st[k]==0)
			{
				miu[i*st[k]]=0;
				//db(i*st[k],miu[i*st[k]]);
				break;
			}
		}
	}
	for(int i=1;i<=7000;i++){
		for(int k=1;k*i<=7000;k++){
			p[k*i][i]=1;
			g[i][k*i]=(miu[k]+2)%2;
		}
	}
	for(int i=1;i<=m;i++){
		op=read();
		if(op==1){
			x=read();y=read();
			f[x]=p[y];
		}
		if(op==2){
			x=read();y=read();z=read();
			f[x]=f[y]^f[z];
		}
		if(op==3){
			x=read();y=read();z=read();
			f[x]=f[y]&f[z];
		}
		if(op==4){
			x=read();y=read();
			tmp=g[y]&f[x];
			int ans=(tmp.count())%2;
			printf("%d",ans);
		}
	}
	return 0;
}