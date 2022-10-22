#include<cstdio>
#include<iostream>
#include<algorithm>
#include<complex>
#include<cmath>
using namespace std;

const int N=3e6+1e3+7;

const double pi=acos(-1);

complex<double>a[N];

int n,m,ans[N],in[N],rev[N],nn,mm;

void fft(complex<double>*a,int f)
{
	for(int i=0;i<nn;i++) 
		if(i<rev[i]) 
			swap(a[i],a[rev[i]]);
    for(int i=1;i<nn;i<<=1)
    {
        complex<double>wn(cos(pi/i),f*sin(pi/i));
        for(int j=0;j<nn;j+=(i<<1))
        {
            complex<double>w(1,0);
            for(int k=0;k<i;k++,w*=wn)
            {
                complex<double> x=a[j+k],y=a[j+k+i]*w;
                a[j+k]=x+y;
				a[j+k+i]=x-y;
            }
        }
    }
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		in[x]=1;
	}
	for(int i=1;i<=m;i++)
		if(in[i])
			for(int j=i;j<=m;j+=i)
				if(!in[j])
				{
					printf("NO\n");
					return 0;
				}
	for(int i=1;i<=m;i++)
		a[i].real()=in[i];
	for(nn=1,mm=0;nn<=2*m;nn<<=1,mm++);
	for(int i=0;i<nn;++i)rev[i]=rev[i>>1]>>1|(1&i)<<(mm-1);
	fft(a,1);
	for(int i=0;i<nn;++i)a[i]*=a[i];
	fft(a,-1);
	for(int i=1;i<=m;++i)
	{
		int now=a[i].real()/nn+0.1;
		if(in[i]&&now<1)
		{
			ans[++ans[0]]=i;
		}
		else if(!in[i]&&now!=0)
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES\n%d\n",ans[0]);
	for(int i=1;i<=ans[0];++i)printf("%d ",ans[i]);
}