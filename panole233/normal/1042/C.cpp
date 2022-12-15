#include<cstdio>
#include<cstring>

int a[200001],n,cntf,cnt0,ma,maa,p0,la;
bool bo[200001];

void print()
{
	bool b=0;
	for (int i=1; i<=n; i++)
		if (bo[i]) {b=1; break;}
	if (!b)
	{
		ma=-1000000001;
		for (int i=1; i<=n; i++)
			if (a[i]>ma) ma=a[i],maa=i;
		bo[maa]=1; print(); return;
	}
	la=0;
	for (int i=1; i<=n; i++)
		if (!bo[i]) 
		{
			if (la) printf("1 %d %d\n",la,i);
			la=i;
		}
	if (la) printf("2 %d\n",la);
	la=0;
	for (int i=1; i<=n; i++)
		if (bo[i]) 
		{
			if (la) printf("1 %d %d\n",la,i);
			la=i;
		}
}

int main()
{
	scanf("%d",&n); cnt0=cntf=0;
	memset(bo,1,sizeof(bo));
	for (int i=1; i<=n; i++) 
	{
		scanf("%d",&a[i]);
		if (a[i]<0) cntf++;
		if (a[i]==0) bo[i]=0;
	}
	if (cntf&1)
	{
		ma=-1000000001;
		for (int i=1; i<=n; i++)
			if (a[i]>ma&&a[i]<0) ma=a[i],maa=i;
		bo[maa]=0;
	}
	print();
	return 0;
}