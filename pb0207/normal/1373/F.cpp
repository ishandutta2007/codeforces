#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e6+1e3+7;

int T;
int n;

ll a[N],b[N],c[N],s[N];

int q[N],head,tail;

int main()
{
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%lld",&b[i]),swap(a[i],b[i]);
		ll nd=0,ad=0,ex=2e9;
		int fl=0;
		for(int i=n;i>=1;i--)
		{
			if(a[i]<nd) 
			{
				puts("NO");
				fl=1;
				break;
			}
			ll res=a[i]-b[i];
			ll ta=min(ex,max(0ll,res-nd));
			ad+=ta;
			ex=min(ex-ta,a[i]-nd-ta);
			nd=max(0ll,nd-res);
		}
		if(!fl)
			puts(ad>=nd?"YES":"NO");
	}	
}