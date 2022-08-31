# include <cstdio>
# include <iostream>
# include <cstring>
# include <set>
# include <algorithm>
# include <vector>

using namespace std;

int N,K,Q[101],S[101],cur[101],temp[101];

bool iseq()
{
	for(int i=1;i<=N;i++)
		if(S[i]!=cur[i])return false;
	return true;
}

int main()
{
	cin>>N>>K;
	for(int i=1;i<=N;i++)cin>>Q[i];
	for(int i=1;i<=N;i++)cin>>S[i];
	for(int i=1;i<=N;i++)cur[i]=i;

	int fwd=-1,bwd=-1;
	for(int i=0;i<=K;i++)
	{
		if(iseq())
		{
			fwd=i;
			break;
		}
		
		for(int j=1;j<=N;j++)
			temp[j]=cur[Q[j]];
		for(int j=1;j<=N;j++)
		{
			cur[j]=temp[j];
			//printf("%d ",cur[j]);
		}
		//printf("\n");
	}

	for(int i=1;i<=N;i++)cur[i]=i;
	for(int i=0;i<=K;i++)
	{
		if(iseq())
		{
			bwd=i;
			break;
		}
		
		for(int j=1;j<=N;j++)
			temp[Q[j]]=cur[j];
		for(int j=1;j<=N;j++)
		{
			cur[j]=temp[j];
			//printf("%d ",cur[j]);
		}
		//printf("\n");
	}

	//printf("%d %d\n",fwd,bwd);	
	if((fwd==bwd)&&((fwd<1)||((fwd==1)&&(K>1))))printf("NO\n");
	else if((fwd>0)&&(fwd<=K)&&((K-fwd)%2==0))printf("YES\n");
	else if((bwd>0)&&(bwd<=K)&&((K-bwd)%2==0))printf("YES\n");
	else printf("NO\n");	

	return 0;
}