#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int block;

struct node{
	int l,r,id;
	bool operator<(const node c)const{
		if(l/block==c.l/block)
			return l/block%2==0?r<c.r:r>c.r;
		return l/block<c.l/block;
	}
}q[200005];

ll n,t,now;
ll a[200005],cnt[1000005],ans[200005];

int readint(){
	int x=0; char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}

void add(int x){now+=(2*cnt[a[x]]+1)*a[x];cnt[a[x]]++;}
void del(int x){cnt[a[x]]--;now-=(2*cnt[a[x]]+1)*a[x];}

int main(){
	n=readint(); t=readint();
	block=sqrt(n);
	for(int i=1;i<=n;i++)
		a[i]=readint();
	for(int i=1;i<=t;i++)
		{q[i].l=readint(); q[i].r=readint(); q[i].id=i;}
	sort(q+1,q+t+1);
	int nl=1,nr=0;
	for(int i=1;i<=t;i++){
		while(nr<q[i].r)add(++nr);
		while(nl>q[i].l)add(--nl);
		while(nr>q[i].r)del(nr--);
		while(nl<q[i].l)del(nl++);
		ans[q[i].id]=now;
	}
	for(int i=1;i<=t;i++)
		printf("%lld\n",ans[i]);
	return 0;
}