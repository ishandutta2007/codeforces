#include<bits/stdc++.h>
using namespace std;
bitset<7010> b[100010],x[7010],u[7010];
int k[7010];
int main()
{
	for(int i=1;i<=7000;i++)
	{
		for(int j=2;j*j<=i;j++)
			if(i%(j*j)==0)
				k[i]=1;
		//cout<<i<<' '<<k[i]<<endl;
	}
	for(int i=1;i<=7000;i++)
		for(int j=i;j<=7000;j+=i)
		{
			x[j][i]=1;
			if(k[j/i]==0)
				u[i][j]=1;
		}
	int n,q;
	cin>>n>>q;
	while(q--)
	{
		int t1,t2,t3,t4;
		scanf("%d%d%d",&t1,&t2,&t3);
		if(t1==1)
			b[t2]=x[t3];
		if(t1==4)
		{
		//	cout<<b[2][1]<<' '<<b[2][2]<<' '<<b[2][4]<<' '<<u[1][4]<<endl;
		//	cout<<(b[t2]&u[t3]).count()<<endl;
			putchar((((b[t2]&u[t3]).count())&1)+48);
		//	cout<<endl;
		}
		if(t1==2)
		{
			scanf("%d",&t4);
			b[t2]=b[t4]^b[t3];
		}
		if(t1==3)
		{
			scanf("%d",&t4);
			b[t2]=b[t4]&b[t3];
		}
	}
}