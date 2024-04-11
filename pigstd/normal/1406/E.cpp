#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=1e5+10;
int n,sum,vis[M],ans=1,p[M],cnt,f;

bool prime(int x)
{
	for (int i=2;i*i<=x;i++)
		if (x%i==0)return 0;
	return 1;
}

signed main()
{
	cin>>n;sum=n;
	for (int i=2;i<=n;i++)
		if (prime(i))p[++cnt]=i;
	int k=sqrt(cnt),x,num;
	for (int i=1;i<=cnt;i++)
	{
		cout<<"B "<<p[i]<<endl;cin>>x;num=0;
		for (int j=p[i];j<=n;j+=p[i])
			if (!vis[j])vis[j]=1,num++,sum--;
		if (x!=num)
		{
			for (int j=p[i];j<=n;j*=p[i])
			{
				cout<<"A "<<j<<endl;cin>>x;
				if (x)ans*=p[i];
				else break;
			}
		}
		if ((i==cnt||i%k==0)&&!f)
		{
			cout<<"A 1"<<endl;cin>>x;
			if (x!=sum)
				for(int j=i-k+1;j<=i;++j)
				{
					for(int w=p[j];w<=n;w*=p[j])
					{
						cout<<"A "<<w<<endl;cin>>x;
						if(x)ans*=p[j],f=1;
						else break;
					}
					if(f)break;
				}
		}
	}
	cout<<"C "<<ans;
	return 0;
}