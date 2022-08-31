#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
typedef long long ll;
int n,m,sn,k,a[100005];
ll cnt,qans[100005];
int mp1[4000005],mp2[4000005];
struct qn
{
	int l,r,id;
	bool operator<(const qn x) const
	{
		return l/sn==x.l/sn?r<x.r:l<x.l;
	}
}q[100005];
void insl(int x)
{
	mp1[a[x]]++;
	mp2[a[x-1]]++;
	cnt+=mp1[a[x-1]^k];
}
void insr(int x)
{
	mp1[a[x]]++;
	mp2[a[x-1]]++;
	cnt+=mp2[a[x]^k];
}
void dell(int x)
{
	cnt-=mp1[a[x-1]^k];
	mp1[a[x]]--;
	mp2[a[x-1]]--;
}
void delr(int x)
{
	cnt-=mp2[a[x]^k];
	mp1[a[x]]--;
	mp2[a[x-1]]--;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	sn=sqrt(n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		a[i]^=a[i-1];
	for(int i=1;i<=m;i++)
		scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+m+1);
	int l=1,r=0;
	for(int i=1;i<=m;i++)
	{
		int ql=q[i].l,qr=q[i].r;
		while(r<qr) insr(++r);
		while(l>ql) insl(--l);
		while(r>qr) delr(r--);
		while(l<ql) dell(l++);
		qans[q[i].id]=cnt;
	}
	for(int i=1;i<=m;i++)
		printf("%I64d\n",qans[i]);
	return 0;
}