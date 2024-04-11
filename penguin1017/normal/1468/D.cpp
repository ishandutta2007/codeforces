#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define pii pair<int,int>
#define ll long long
#define fi first
#define se second
#define vi vector<int> 
#define pb push_back
using namespace std;
const int N=5e5+9;
struct node{
	int u,v,w;
	node(int u=0,int v=0,int w=0):u(u),v(v),w(w){} 
};

int s[N],v[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,a,b;
		scanf("%d%d%d%d",&n,&m,&a,&b);
		rep(i,0,m)scanf("%d",&s[i]);
		sort(s,s+m);
		int k=abs(b-a)-1;
		k=min(k,m);
		int l=0,r=k+1;
		int t=b>a?b-1:n-b;
		while(l<r){
			int mid=l+r>>1;
			per(i,0,mid)v[i]=s[i]+(mid-i);
			int sum=0;
			rep(i,0,mid)if(v[i]<=t)++sum;
			if(sum==mid)l=mid+1;
			else r=mid;
		}
		printf("%d\n",r-1);
	}
}