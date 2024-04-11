#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=2e5+10;
int T,n,x,a[M<<1],ans1[M],ans2[M],t[M*10];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

bool cmp(int a,int b){return a>b;}

signed main()
{
	cin>>T;
	while(T--)
	{
		for (int i=1;i<=2*n;i++)t[a[i]]=0;
		n=read();
		for (int i=1;i<=n*2;i++)a[i]=read();
		sort(a+1,a+1+2*n,cmp);bool f=0;
		for (int i=2;i<=2*n;i++)
		{
			for (int i=1;i<=2*n;i++)t[a[i]]=0;
			for (int i=1;i<=2*n;i++)t[a[i]]++;
			for (int i=1;i<=n;i++)ans1[i]=ans2[i]=0;x=0;
			bool kkk=1;
			ans1[1]=a[1];t[a[1]]--;
			int x=a[i]+a[1];t[a[i]]--;ans2[1]=a[i];
			int now=2;
			for (int j=2;j<=n;j++)
			{
				while(t[a[now]]==0)now++;
				if(now>2*n)break;
				ans1[j]=a[now];t[a[now]]--;
				if (t[ans1[j-1]-a[now]])ans2[j]=ans1[j-1]-a[now],t[ans1[j-1]-a[now]]--;
				else {kkk=0;break;}
			}
			if (kkk){f=1;break;}
		}
		if (f)
		{
			puts("YES");
			cout<<ans1[1]+ans2[1]<<endl;
			for (int i=1;i<=n;i++)cout<<ans1[i]<<' '<<ans2[i]<<endl;
			continue;
		}else puts("NO");
	}
	return 0;
}
/*
1
5
1 2 3 4 5 6 7 14 3 11

*/