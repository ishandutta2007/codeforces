#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<math.h>
#include<ctime>
#include<queue>
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define mp make_pair
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define fi first
#define se second
#define da(x) cout<<"sese:"<<x<<endl;
#define db(x,y) cout<<"???"<<x<<" "<<y<<endl;
#define dc(x,y,z) cout<<"!!!!:"<<x<<" "<<y<<" "<<z<<endl;
#define dd(x,y,z,w) cout<<"yiw:"<<x<<" "<<y<<" "<<z<<" "<<w<<endl;
inline int read(){
	char c=getchar();int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*x;
}
const int N=1e5+55;
unordered_set<int>f[N];
priority_queue<pii>q;
int T,n,m,k,x,y,st[N],vis[N],top;
int main()
{
//	freopen("data.in","r",stdin);
//	freopen("ans.out","w",stdout);
	T=read();
	while(T--){
		n=read();m=read();k=read();
		for(int i=1;i<=m;i++){
			x=read();y=read();
			f[x].insert(y);
			f[y].insert(x);
		}
		if(k==1){
			printf("2 1\n");
			for(int i=1;i<=n;i++)f[i].clear();
			continue;
		}
		for(int i=1;i<=n;i++)q.push(mp(-f[i].size(),i));
		int flag=0;
		while(!q.empty()){
			int u=q.top().se;q.pop();
			if(vis[u])continue;
			vis[u]=1;
			if(f[u].size()>=k){
				flag=1;
				break;
			}
			if(f[u].size()==k-1 and (k*(k-1)/2)<=m){
				top=0;
				bool bj=0;
				for(auto it=f[u].begin();it!=f[u].end();++it){
					st[++top]=*it;
				}
				for(int i=1;i<=top;i++){
					for(int j=1;j<=top;j++){
						if(i==j)continue;
						if(f[st[i]].find(st[j]) == f[st[i]].end())bj=1;
						if(bj)break;
					}
					if(bj)break;
				}
				if(!bj){
					st[++top]=u;
					flag=2;
					break;
				}
			}
			for(auto it=f[u].begin();it!=f[u].end();++it)f[*it].erase(u),q.push(mp(-f[*it].size(),*it));
			f[u].clear();
		}
		if(flag){
			if(flag==1){
				top=0;
				for(int i=1;i<=n;i++)if(f[i].size()>=k)st[++top]=i;
				printf("%d %d\n",1,top);
				for(int i=1;i<=top;i++)printf("%d ",st[i]);
			}
			else{
				printf("2\n");
				for(int i=1;i<=top;i++)printf("%d ",st[i]);
			}
			puts("");
		}
		else puts("-1");
		for(int i=1;i<=n;i++){
			f[i].clear();
			while(!q.empty()){
				q.pop();
			}
			vis[i]=0;
		}
	}
	return 0;
}
/*
1
10 15 3
1 2
2 3
3 4
4 5
5 1
1 7
2 8
3 9
4 10
5 6
7 10
10 8
8 6
6 9
9 7
*/