#include<bits/stdc++.h>
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1e4+10;
int T,a[M],n,ans1[M],ans2[M],ans3[M];

int main()
{
	T=read();
	while(T--)
	{
		n=read();int sum=0;
		for (int i=1;i<=n;i++)a[i]=read(),sum+=a[i];
		if (sum%n!=0){puts("-1");continue;}
		int k=sum/n;
		cout<<3*n-3<<endl;
		for (int i=2;i<=n;i++)
		{
			int d=a[i]%i;
			cout<<1<<' '<<i<<' '<<(i-d)%i<<endl;
			a[i]+=(i-d)%i,a[1]-=(i-d)%i;
			cout<<i<<' '<<1<<' '<<a[i]/i<<endl;
			a[1]+=a[i],a[i]=0;
		}
		for (int i=2;i<=n;i++)
			cout<<1<<' '<<i<<' '<<k<<endl;
	}
}