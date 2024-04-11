#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+1;
int n,sa[N],sb[N],a1[N],b1[N],suma,sumb,q[N];
struct nd{int w,id;}a[N],b[N];
bool cmp(nd a,nd b){return a.w>b.w;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i].w),a[i].id=i,a1[i]=a[i].w,suma+=a[i].w;
	for(int i=1;i<=n;++i)scanf("%d",&b[i].w),b[i].id=i,b1[i]=b[i].w,sumb+=b[i].w;
	sort(a+1,a+n+1,cmp);
	q[++q[0]]=a[1].id;
	for(int i=2;i<n;i+=2)
	{
		if(b1[a[i].id]>b1[a[i+1].id])
		q[++q[0]]=a[i].id;
		else
		q[++q[0]]=a[i+1].id;
	}
	if(n%2==0)q[++q[0]]=a[n].id;
	cout<<n/2+1<<endl;
	for(int i=1;i<=q[0];++i)cout<<q[i]<<" ";
	
}