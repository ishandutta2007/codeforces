#include<bits/stdc++.h>

#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,cys;
ll ans;
int cnt1[1000005],cnt2[1000005],s[300005],a[300005];
pii maxa[1100000];

int mod(int x){return x>=cys?x-cys:x;}

void build(int id,int l,int r){
	if(l==r) return (void)(maxa[id]=mp(a[l],l));
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	maxa[id]=max(maxa[id<<1],maxa[id<<1|1]);
}

pii query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return maxa[id];
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	else return max(query(id<<1,l,mid,ql,mid),query(id<<1|1,mid+1,r,mid+1,qr));
}

void work(int l,int r,int k){
	pii now=query(1,1,n,l,r);
	if(r-now.se>now.se-l){
		if(l<now.se) work(l,now.se-1,0);
		if(now.se<r) work(now.se+1,r,1);
		cnt1[s[now.se]]++,cnt2[s[now.se-1]]++;
		for(int i=l;i<=now.se;i++) ans+=cnt1[(s[i-1]+now.fi)%cys];
		for(int i=l;i<=now.se-1;i++) cnt1[s[i]]++,cnt2[s[i-1]]++;
		if(!k) for(int i=l;i<=r;i++) cnt1[s[i]]--,cnt2[s[i-1]]--;
	}
	else{
		if(now.se<r) work(now.se+1,r,0);
		if(l<now.se) work(l,now.se-1,1);
		cnt1[s[now.se]]++,cnt2[s[now.se-1]]++;
		for(int i=now.se;i<=r;i++) ans+=cnt2[mod(s[i]-now.fi%cys+cys)];
		for(int i=now.se+1;i<=r;i++) cnt1[s[i]]++,cnt2[s[i-1]]++;
		if(!k) for(int i=l;i<=r;i++) cnt1[s[i]]--,cnt2[s[i-1]]--;
	}
}

int main(){
	n=readint(); cys=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) s[i]=mod(s[i-1]+a[i]%cys);
	build(1,1,n);
	work(1,n,1);
	printf("%lld\n",ans-n);
	return 0;
}