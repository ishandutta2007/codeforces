# include <cstdio>
# include <iostream>
# include <cstring>
# include <set>
# include <algorithm>
# include <vector>

using namespace std;

int bestto0[360361],besttoB[360361];
int LCMarray[]={1,1,2,6,12,60,60,420,840,2520,2520,27720,27720,360360,360360,360360};

int main()
{
	long long A,B,K;
	cin>>A>>B>>K;

	if(B==A)
	{
		cout<<0<<endl;
		return 0;
	}

	int LCM=LCMarray[K];
	for(int i=1;i<=LCM;i++)
	{
		bestto0[i]=bestto0[i-1]+1;
		for(int j=2;j<=K;j++)
		{
			if(i-(i%j)>=0)bestto0[i]=min(bestto0[i],bestto0[i-(i%j)]+1);
		}
	}

	for(int i=(B%LCM)+1;i<=LCM;i++)
	{
		besttoB[i]=besttoB[i-1]+1;
		for(int j=2;j<=K;j++)
		{
			if(i-(i%j)>=(B%LCM))besttoB[i]=min(besttoB[i],besttoB[i-(i%j)]+1);
		}
	}

	long long nexthigh=((B/LCM)+1)*LCM;
	long long nextlow=((A/LCM)*LCM);

	if(nextlow<nexthigh)cout<<besttoB[A%LCM]<<endl;
	else cout<<besttoB[LCM]+bestto0[A%LCM]+bestto0[LCM]*((nextlow-nexthigh)/LCM)<<endl;
	return 0;
}