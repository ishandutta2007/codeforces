#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+1;
int n,a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	int g=0,tot=0;
	for(int i=1;i<=n;++i)g=__gcd(g,a[i]);
	if(g!=1){cout<<"YES"<<endl<<0;return 0;}
	for(int i=1;i<=n;++i)
	{
		if(a[i]&1)
		{
			if(a[i+1]&1)tot++,i++;
			else tot+=2,i++;
		}
	}
	cout<<"YES"<<endl<<tot;
}