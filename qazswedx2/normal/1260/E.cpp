#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
int n,a[1000005];
multiset<int> st;
ll tans=0;
int main()
{
	scanf("%d",&n);
	int nw=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==-1) nw=i;
	}
	for(int i=1;i<nw;i++)
		a[i]=0;
	for(int i=nw+1;i<=n;i++)
		a[i-1]=a[i];
	for(int i=n;i>1;i>>=1)
	{
		for(int j=i-1;j<min(i*2-1,n);j++)
			st.insert(a[j]);
		tans+=*st.begin();
		st.erase(st.begin());
	}
	printf("%I64d",tans);
	return 0;
}