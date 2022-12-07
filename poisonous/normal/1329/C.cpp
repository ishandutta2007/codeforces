#include<bits/stdc++.h>
using namespace std;
int num[2400010],p[1100010],k[1100010],sz[2400010],lv[1100010];
vector<int> xl;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int h,g;
		cin>>h>>g;
		long long ans=0;
		for(int i=1;i<(1<<h);i++)
		{
			scanf("%d",&num[i]);
			p[num[i]]=i;
			k[i]=num[i];
			sz[i]=1;
			ans+=num[i];
		}
		for(int i=(1<<h)-1;i>=1;i--)
		{
			sz[i]=sz[i]+sz[i*2]+sz[i*2+1];
			lv[i]=(int)(log(sz[i]+0.5)/log(2));
		}
		sort(k+1,k+(1<<h));
		int x=0;
		for(int i=(1<<h)-1;i>=1;i--)
		{
			int j=p[k[i]],can=1;
			while(j<(1<<h))
			{
				int nlv=lv[j]-(h-g);
				if(nlv>=0)
					if(sz[j]-1<(1<<nlv))
					{
						can=0;
						break;
					}
				if(num[j*2]>num[j*2+1])
					j=j*2;
				else
					j=j*2+1;
			}
			if(can)
			{
				j=p[k[i]];
				xl.push_back(j);
				while(j<(1<<h))
				{
					sz[j]--;
					if(num[j*2]>num[j*2+1])
					{
						num[j]=num[j*2];
						if(num[j]!=0)
							p[num[j]]=j;
						j=j*2;
					}
					else
					{
						num[j]=num[j*2+1];
						if(num[j]!=0)
							p[num[j]]=j;
						j=j*2+1;
					}
					if(num[j]==0)
						break;
				}
				ans-=k[i];
			}
		}
		cout<<ans<<endl;
		for(int i=0;i<xl.size();i++)
			printf("%d ",xl[i]);
		xl.clear();
		for(int i=1;i<(1<<h);i++)
		{
			p[k[i]]=sz[i]=lv[i]=num[i]=0;
			k[i]=0;
		}
		cout<<endl;
	}
		
}