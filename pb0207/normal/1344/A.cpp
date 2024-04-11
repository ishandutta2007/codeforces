#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n,a[N],vis[N];

int main()
{
//	x+a_x mod n = y+ a_y mod n
//	a_x mod n- a_y mod n = y-x
//	a_i - a_j = j+xn-i+yn
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		fill(vis,vis+n+1,0);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			int w=(a[i]%n+n+i)%n;
			if(vis[w])
				ans=0;
			vis[w]=1;
		}
		puts(ans?"YES":"NO");
	}
}