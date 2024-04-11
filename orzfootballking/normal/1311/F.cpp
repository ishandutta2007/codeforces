#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
struct node{
	int id,x,v;
}a[200005];
int n,t[200005]; 
bool cmp1(node t1,node t2){RE t1.x<t2.x;}
bool cmp2(node t1,node t2){RE t1.v>t2.v||(t1.v==t2.v&&t1.x>t2.x);}
int bit[200005],cnt[200005];
int get(int p,int s){
	int re=0;
	while(p){
		re=re+s*cnt[p]-bit[p];
		p=p-(p&-p);
	}
	RE re;
}
void up(int p,int s){
	while(p<=n){
		bit[p]=bit[p]+s;cnt[p]++;
		p=p+(p&-p);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n){
		cin>>a[i].x;a[i].id=i;
	}
	FOR(i,1,n)cin>>a[i].v;
	sort(a+1,a+n+1,cmp1);
	int ans=0,sum=0;
	FOR(i,1,n){
		ans=ans+a[i].x*(i-1)-sum;
		sum+=a[i].x;
		t[a[i].id]=a[i].x;a[i].x=i;
	}
	sort(a+1,a+n+1,cmp2);
	FOR(i,1,n){
		ans=ans-get(a[i].x-1,t[a[i].id]);
		up(a[i].x,t[a[i].id]);
	}
	cout<<ans;
	RE 0;
}