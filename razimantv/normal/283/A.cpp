# include <cstdio>

int seg[1<<19];
const int base =1<<18;

void update(int node,int l,int r,int L,int R,int x)
{
	if(l==L&&r==R)
	{
		seg[node]+=x;
		return;
	}
	int M=(L+R)>>1;
	if(r<=M)update(node<<1,l,r,L,M,x);
	else if(l>M)update((node<<1)|1,l,r,M+1,R,x);
	else update(node<<1,l,M,L,M,x),update((node<<1)|1,M+1,r,M+1,R,x);
}

int main()
{
	long long tot=0;

	int N;
	scanf("%d",&N);

	int len=1;
	for(int i=0;i<N;i++)
	{
		int q;
		scanf("%d",&q);
		if(q==1)
		{
			int a,x;
			scanf("%d%d",&a,&x);
			tot+=a*x;
			update(1,0,a-1,0,base-1,x);
			printf("%.8lf\n",tot/(double)len);
		}
		else if(q==2)
		{
			int a;
			scanf("%d",&a);
			seg[base+len++]+=a;
			tot+=a;
			printf("%.8lf\n",tot/(double)len);
		}
		else if(q==3)
		{
			int temp=0;
			for(int i=base+--len;i;i>>=1)
				temp+=seg[i];
			seg[base+len]-=temp;
			tot-=temp;
			printf("%.8lf\n",tot/(double)len);
		}
	}
	return 0;
}