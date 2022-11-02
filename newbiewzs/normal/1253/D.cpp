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
const int N=2e5+55;
int n,m,st[N],top,x[N],y[N],f[N];
int find(int x){
	if(f[x]!=x)return f[x]=find(f[x]);
	else return x;
}
priority_queue<int>v[N];
vi cd[N];
int bh[N],tot,pd[N],vis[N];
int main(){
//	freopen("data.in","r",stdin);
	n=read();m=read();
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		x[i]=read();y[i]=read();
		f[find(x[i])]=find(y[i]);
	}
	for(int i=1;i<=n;i++){
		if(!bh[find(i)])bh[find(i)]=++tot;
		v[bh[find(i)]].push(-i);
		bh[i]=bh[find(i)];
		cd[bh[find(i)]].pb(i);
	}
	int ans=0;
	for(int i=1;i<=tot;i++){
	//	cout<<i<<endl;
		int ne=i;
		vis[i]=1;
		while(!v[i].empty()){
			int u=-v[i].top();
			v[i].pop();
			if(v[i].size()==0)
			{
				continue;
			}
			if(bh[u+1]!=ne){
				ans++;
				if(v[i].size()<v[bh[u+1]].size())
				{
					swap(v[i],v[bh[u+1]]);
					for(unsigned int k=0;k<cd[ne].size();k++)bh[cd[ne][k]]=bh[u+1],cd[bh[u+1]].pb(cd[ne][k]);
					ne=bh[u+1];
					while(!v[bh[u+1]].empty()){
						int tmp=-v[bh[u+1]].top();
						v[bh[u+1]].pop();
						v[i].push(-tmp);
					}
				}
				else{
					while(!v[bh[u+1]].empty()){
						int tmp=-v[bh[u+1]].top();
						v[bh[u+1]].pop();
						v[i].push(-tmp);
					}
					int ys=bh[u+1];
					for(unsigned int k=0;k<cd[ys].size();k++)
					{
						bh[cd[ys][k]]=ne,cd[ne].pb(cd[ys][k]);
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}