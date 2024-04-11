#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define rt 0 
using namespace std;
const int N=3e6+9;
struct node{
	int pos,l,r;
}tree[N];
int cnt,ans=1<<30;
void dfs(int u,int num){
	if(!tree[u].pos){
		ans=min(ans,num);
		return;
	}
	if(tree[u].l){
		if(tree[u].r)dfs(tree[u].l,num^(1<<(tree[u].pos-1)));
		else dfs(tree[u].l,num);
	}
	if(tree[u].r){
		if(tree[u].l)dfs(tree[u].r,num^(1<<(tree[u].pos-1)));
		else dfs(tree[u].r,num);
	}
}
int main()
{
	tree[rt].pos=30;
	int n,a;
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%d",&a);
		int p=rt;
		per(j,0,30){
			if((1<<j)&a){
				if(tree[p].r)p=tree[p].r;
				else{
					tree[p].r=++cnt;
				//	tree[cnt].fa=p;
					tree[cnt].pos=j;
					p=cnt;
				}
			}
			else{
				if(tree[p].l)p=tree[p].l;
				else{
					tree[p].l=++cnt;
				//	tree[cnt].fa=p;
					tree[cnt].pos=j;
					p=cnt;
				}
			}
		}
	}
	dfs(rt,0);
	cout<<ans; 
 }