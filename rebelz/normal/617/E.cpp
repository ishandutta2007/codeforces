#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,m,k,block;
ll now;
int cnt[2000005],a[100005];
ll ans[100005];

struct node{
	int l,r,id;
	bool operator<(const node c)const{
		if(l/block==c.l/block) return l/block%2==0?r<c.r:r>c.r;
		return l/block<c.l/block;
	}
}q[100005];

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void add(int x){now+=cnt[a[x]^k];cnt[a[x]]++;}
void del(int x){cnt[a[x]]--;now-=cnt[a[x]^k];}

int main(){
	n=readint(); m=readint(); k=readint(); block=sqrt(n);
	for(int i=1;i<=n;i++) a[i]=readint()^a[i-1];
	for(int i=1;i<=m;i++){
		q[i].l=readint()-1; q[i].r=readint();
		q[i].id=i;
	}
	sort(q+1,q+m+1);
	int nl=1,nr=0;
	for(int i=1;i<=m;i++){
		while(q[i].r>nr) add(++nr);
		while(q[i].l>nl) del(nl++);
		while(q[i].r<nr) del(nr--);
		while(q[i].l<nl) add(--nl);
		ans[q[i].id]=now;
	}
	for(int i=1;i<=m;i++) printf("%lld\n",ans[i]);
	printf("\n");
	return 0;
}