#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define vi vector<int>
#define pb push_back
#define ll long long 
using namespace std;
const int N=1e5+9;
const int S=320;
struct node{
	int l,r,id;
	node(int l=0,int r=0,int id=0):l(l),r(r),id(id){}
	bool operator <(const node &o) const {
		if(l/S!=o.l/S)return l/S<o.l/S;
		return r<o.r;
	} 
}p[N];
int a[N],cnt[N],sum[N],b[N];
ll ans[N];
vi g;
bool vis[N];
void add(int x){
	if(vis[x]){
		cnt[x]++;
		return;
	}
	sum[cnt[x]]--;
	sum[++cnt[x]]++;
}
void del(int x){
	if(vis[x]){
		cnt[x]--;
		return;
	}
	sum[cnt[x]]--;
	sum[--cnt[x]]++;
}
priority_queue<int,vi,greater<int> > PQ;
ll solve(){
	while(PQ.size())PQ.pop();
	ll res=0;
	rep(i,1,S)b[i]=sum[i];
	for(auto u:g){
		if(cnt[u]>=S)PQ.push(cnt[u]);
		else b[cnt[u]]++; 
	}
/*	rep(i,1,S){
		if(b[i])cout<<i<<' '<<b[i]<<"B\n";
	}*/
	rep(i,1,S){
		if(!b[i])continue;
		int sum=b[i]>>1;
		b[i]-=sum<<1;
		res+=i*sum<<1;
		if(i*2>=S){
			while(sum--)PQ.push(i*2);
		}
		else{
			b[i<<1]+=sum;
		}
		if(b[i]){
			int p=i+1;
			for(;p<S;++p)if(b[p])break;
			if(p==S)PQ.push(i);
			else{
				b[p]--;
				res+=i+p;
				if(i+p>=S)PQ.push(i+p);
				else b[i+p]++;
			}
		}
	} 
	while(PQ.size()>1){
		int u=PQ.top(),v;
		PQ.pop();v=PQ.top();PQ.pop();
		res+=u+v;
		PQ.push(u+v);
	}
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%d",&a[i]),cnt[a[i]]++;
	rep(i,1,N)if(cnt[i]>=S)g.pb(i),vis[i]=1;
	else sum[cnt[i]]++;
	int q;
	scanf("%d",&q);
	rep(i,0,q){
		int l,r;
		scanf("%d%d",&l,&r);
		p[i]=node(l,r,i);
	}
	sort(p,p+q);
	int l=1,r=n;
	rep(i,0,q){
		for(;l>p[i].l;--l)add(a[l-1]);
		for(;r<p[i].r;++r)add(a[r+1]);
		for(;l<p[i].l;++l)del(a[l]);
		for(;r>p[i].r;--r)del(a[r]);
	//	cout<<p[i].id<<"check\n"; 
		ans[p[i].id]=solve();
	}
	rep(i,0,q)printf("%lld\n",ans[i]);
}
/*
20
457 506 660 660 457 457 832 660 457 457 832 793 457 793 506 506 793 506 832 832



69
1 8
8 11
7 7
8 16
1 12
13 14
3 3
1 7
15 18
7 12
13 13
3 13
16 16
10 17
7 18
2 6
16 20
3 20
8 12
2 17
12 19
7 15
9 13
14 14
9 19
11 12
5 6
6 6
2 2
1 16
7 19
7 16
6 15
5 5
7 20
1 10
11 11
15 16
12 20
13 20
15 15
4 18
12 18
3 9
7 17
5 11
12 12
6 17
4 8
4 20
4 7
6 16
6 10
7 10
2 15
2 8
5 15
1 9
4 13
2 20
9 15
16 17
7 13
19 19
5 7
5 18
1 18
20 20
4 11
*/