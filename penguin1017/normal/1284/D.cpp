#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define lb(x) ((x)&(-x))
using namespace std;
const int N=1e5+9;
const int pp=998244353;
const int mod=1e9+7;
ll val[N],sum[N],sum2[N],che[N],che2[N];
struct node{
	int l,r,id;
}p[N],p2[N];
int n;
bool cmp(node a,node b){
	return a.l<b.l;
}
bool cmp2(node a,node b){
	return a.r<b.r;
}
int find(int pos){
	int l=0,r=n;
	while(l<r){
		int mid=l+r>>1;
		if(p[mid].l>pos)r=mid;
		else l=mid+1;
	}
	return l;
}
int find2(int pos){
	int l=0,r=n;
	while(l<r){
		int mid=l+r>>1;
		if(p2[mid].l>pos)r=mid;
		else l=mid+1;
	}
	return l;
}
int find_(int pos){
	int l=0,r=n;
	while(l<r){
		int mid=l+r>>1;
		if(p[mid].r<pos)l=mid+1;
		else r=mid;
	}
	return l;
}
int find_2(int pos){
	int l=0,r=n;
	while(l<r){
		int mid=l+r>>1;
		if(p2[mid].r<pos)l=mid+1;
		else r=mid;
	}
	return l;
}
int main()
{
	val[0]=1;
	rep(i,1,N)val[i]=val[i-1]*pp%mod;
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%d%d%d%d",&p[i].l,&p[i].r,&p2[i].l,&p2[i].r);
		p[i].id=i+1,p2[i].id=i+1;
	}
	sort(p,p+n,cmp);
	sort(p2,p2+n,cmp);
	rep(i,0,n){
		sum[i+1]=val[p[i].id];
		sum2[i+1]=val[p2[i].id];
	}
	rep(i,1,n+1)sum[i]+=sum[i-1],sum2[i]+=sum2[i-1];
	rep(i,0,n){
		int pos=p[i].r;
		pos=find(pos);
		che[p[i].id]=sum[n]-sum[pos];
	}
	rep(i,0,n){
		int pos=p2[i].r;
		pos=find2(pos);
		che2[p2[i].id]=sum2[n]-sum2[pos];
	}
	/////////////////
	sort(p,p+n,cmp2);
	sort(p2,p2+n,cmp2);
	rep(i,0,n){
		sum[i+1]=val[p[i].id];
		sum2[i+1]=val[p2[i].id];
	}
	rep(i,1,n+1)sum[i]+=sum[i-1],sum2[i]+=sum2[i-1];
	rep(i,0,n){
		int pos=p[i].l;
		pos=find_(pos);
		che[p[i].id]+=sum[pos];
	}
	rep(i,0,n){
		int pos=p2[i].l;
		pos=find_2(pos);
		che2[p2[i].id]+=sum2[pos];
	}
	rep(i,1,n+1){
		if(che[i]!=che2[i]){
		//	cout<<che[i]<<' '<<che2[i]<<"check\n";
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}
/*
4
264867940 499429904 220955759 781251486
291875388 479775959 420934162 592410327
52543740 554108790 274827825 959163500
296520478 486243278 118208940 918104336
*/