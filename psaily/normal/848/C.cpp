#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
 
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef unsigned long long ull;
// head
 
const int N=4e5+5;
set<int> st[N];
set<int>::iterator it;
int n,q,m,idd,c[N];
int pre[N],nxt[N];
ll ans[N];
 
struct opes {
	int op,x,y,val,id;	
}nd[N*2];
 
bool chk(int x) {return x&&(x!=n+1);}
void calc(int p,int las) {
	 // bug(p),debug(las);
	// (i,las) -> (i,now) 
	if (chk(p)&&chk(pre[p])) nd[++m]=(opes) {0,p,pre[p],-(p-pre[p]),0};
	if (chk(p)) pre[p]=las;
	if (chk(las)) nxt[las]=p;
	if (chk(p)&&chk(pre[p])) nd[++m]=(opes) {0,p,pre[p],+(p-pre[p]),0};
}
 
struct bit {
	ll sum[N];
	int lowbit(int x) {return x&(-x);}
	void update(int x,int a) {
		if (!x||!a) return;
		for (;x<=n;x+=lowbit(x)) sum[x]+=a;
	}
	ll query(int x) {
		if (!x) return 0;
		ll res=0;
		for (;x;x-=lowbit(x)) res+=sum[x];
		return res;
	}
	ll gao(int x) {// >=x
		return query(n)-query(x-1);
	}
}bit;
 
bool cmpx(opes a,opes b) {return a.x<b.x;}
 
void cdq(int l,int r) {//x
	if (l==r) return;
	int mid=(l+r)>>1;
	cdq(l,mid); cdq(mid+1,r);
	int ll=l;
	rep(i,mid+1,r+1) if (nd[i].op==1) {
		while (ll<=mid&&nd[ll].x<=nd[i].x) {
			if (!nd[ll].op) bit.update(nd[ll].y,nd[ll].val);
			ll++;
		}
		ans[nd[i].id]+=bit.gao(nd[i].y);
	}
	rep(i,l,ll) if (!nd[i].op) bit.update(nd[i].y,-nd[i].val);
	inplace_merge(nd+l,nd+mid+1,nd+r+1,cmpx);
}
 
int main() {
	scanf("%d%d",&n,&q);
	rep(i,1,n+1) st[i].insert(0),st[i].insert(n+1);
	rep(i,1,n+1) {
		scanf("%d",&c[i]);
		st[c[i]].insert(i);
		it=st[c[i]].find(i);
		// it++; nxt[i]=*it; it--;
		it--; pre[i]=*it,nxt[*it]=i;
		nd[++m]=(opes) {0,i,pre[i],i-pre[i],0};
	}
	rep(i,1,n+1) {
		it=st[i].end(); it--,it--;
		nxt[*it]=n+1;
	}
	// puts("---");
	rep(i,1,q+1) {
		int op,a,b;
		scanf("%d%d%d",&op,&a,&b);
		
		if (op==2) nd[++m]=(opes) {1,b,a,0,++idd};
		else {
			// c[a]=b
			st[c[a]].erase(a);
			c[a]=b;
			st[c[a]].insert(a);
			
			int t1=pre[a],t2=nxt[a];
			calc(t2,t1);
			
			it=st[c[a]].find(a);
			it--; t1=*it; it++;
			it++; t2=*it; it--;
			calc(t2,a),calc(a,t1);
		}
	}
	// rep(j,1,m+1) printf("op=%d x=%d y=%d val=%lld\n",nd[j].op,nd[j].x,nd[j].y,(long long)nd[j].val);
	cdq(1,m);	
	rep(i,1,idd+1) printf("%lld\n",ans[i]);
	return 0;	
}