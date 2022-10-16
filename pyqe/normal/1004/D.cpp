#include <bits/stdc++.h>

using namespace std;

long long t,fq[1000069],n,m,y,x,bg,bg2,bg3;
bool bad;

int main()
{
	long long i,k,mx=-1;
	
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
		mx=max(mx,k);
	}
	if(fq[0]!=1)
	{
		bad=1;
	}
	else if(t==1)
	{
		n=1;
		m=1;
		y=1;
		x=1;
	}
	else if(fq[mx]==4)
	{
		n=round(sqrt(t));
		if(n*n!=t||n%2==0)
		{
			bad=1;
		}
		else
		{
			m=n;
			y=n/2+1;
			x=m/2+1;
			for(bg=1;fq[bg]==bg*4;bg++);
			bg--;
			if(bg!=y-1)
			{
				bad=1;
			}
			else
			{
				for(i=1;i<=mx;i++)
				{
					if(i<=bg)
					{
						k=i*4;
					}
					else
					{
						k=(bg+bg-i+1)*4;
					}
					if(fq[i]!=k)
					{
						bad=1;
						break;
					}
				}
			}
		}
	}
	else if(fq[mx]==2)
	{
		for(bg=1;fq[bg]==bg*4;bg++);
		bg--;
		n=bg+bg+1;
		y=bg+1;
		if(t%n!=0)
		{
			bad=1;
		}
		else
		{
			m=t/n;
			x=mx-y+2;
			if(x+bg>m)
			{
				bad=1;
			}
			else
			{
				for(i=1;i<=mx;i++)
				{
					if(i<=bg)
					{
						k=i*4;
					}
					else if(i<=m-x)
					{
						k=n*2;
					}
					else if(i<=x-1)
					{
						k=n+max((long long)0,n-(i-m+x)*2+1);
					}
					else
					{
						k=n-(i-x+1)*2+1+max((long long)0,n-(i-m+x)*2+1);
					}
					if(fq[i]!=k)
					{
						bad=1;
						break;
					}
				}
			}
		}
		if(bad)
		{
			bad=0;
			for(bg2=bg+1;1;bg2++)
			{
				k=bg2*4-(bg2-bg)*2+1;
				if(fq[bg2]!=k)
				{
					break;
				}
			}
			bg2--;
			if(k-fq[bg2+1]==1)
			{
				m=bg+bg2+1;
				x=bg2+1;
				if(t%m!=0)
				{
					bad=1;
				}
				else
				{
					n=t/m;
					y=n/2+1;
					if(x+y-2!=mx||y<=x)
					{
						bad=1;
					}
					else
					{
						for(i=1;i<=mx;i++)
						{
							if(i<=bg)
							{
								k=i*4;
							}
							else if(i<=bg2)
							{
								k=i*4-(i-bg)*2+1;
							}
							else if(i<=y-1)
							{
								k=m*2;
							}
							else
							{
								k=n-(i-x+1)*2+1+max((long long)0,n-(i-bg)*2+1);
							}
							if(fq[i]!=k)
							{
								bad=1;
								break;
							}
						}
					}
				}
			}
			else
			{
				n=bg2+bg2+1;
				y=bg2+1;
				if(t%n!=0)
				{
					bad=1;
				}
				else
				{
					m=t/n;
					x=mx-y+2;
					if(x-1<bg2||m-bg!=x)
					{
						bad=1;
					}
					else
					{
						for(i=1;i<=mx;i++)
						{
							if(i<=bg)
							{
								k=i*4;
							}
							else if(i<=bg2)
							{
								k=i*4-(i-bg)*2+1;
							}
							else if(i<=x-1)
							{
								k=n+max((long long)0,n-(i-bg)*2+1);
							}
							else
							{
								k=n-(i-x+1)*2+1+max((long long)0,n-(i-bg)*2+1);
							}
							if(fq[i]!=k)
							{
								bad=1;
								break;
							}
						}
					}
				}
			}
		}
	}
	else if(fq[mx]==1)
	{
		for(bg=1;fq[bg]==bg*4;bg++);
		bg--;
		for(bg2=bg+1;1;bg2++)
		{
			k=bg2*4-(bg2-bg)*2+1;
			if(fq[bg2]!=k)
			{
				break;
			}
		}
		bg2--;
		m=bg+bg2+1;
		x=bg2+1;
		if(t%m!=0)
		{
			bad=1;
		}
		else
		{
			n=t/m;
			y=mx-x+2;
			if(y-1<=n-y||n-y<=bg2)
			{
				bad=1;
			}
			else
			{
				for(i=1;i<=mx;i++)
				{
					if(i<=bg)
					{
						k=i*4;
					}
					else if(i<=bg2)
					{
						k=i*4-(i-bg)*2+1;
					}
					else if(i<=n-y)
					{
						k=m*2;
					}
					else if(i<=y-1)
					{
						k=m+max((long long)0,bg-(i-n+y-1))+max((long long)0,bg2-(i-n+y-1));
					}
					else
					{
						k=max((long long)0,bg-(i-n+y-1))+max((long long)0,bg2-(i-n+y-1))+max((long long)0,bg-(i-y))+max((long long)0,bg2-(i-y));
					}
					if(fq[i]!=k)
					{
						bad=1;
						break;
					}
				}
			}
		}
		if(bad)
		{
			bad=0;
			for(bg3=bg2+1;1;bg3++)
			{
				k=bg3+1+bg+bg2+max((long long)0,bg-(bg3-bg2-1));
				if(fq[bg3]!=k)
				{
					break;
				}
			}
			bg3--;
			m=bg+bg3+1;
			x=bg3+1;
			if(t%m!=0)
			{
				bad=1;
			}
			else
			{
				n=t/m;
				y=n-bg2;
				if(y+x-2!=mx||y-1<=bg2||y<x)
				{
					bad=1;
				}
				else
				{
					for(i=1;i<=mx;i++)
					{
						if(i<=bg)
						{
							k=i*4;
						}
						else if(i<=bg2)
						{
							k=i*4-(i-bg)*2+1;
						}
						else if(i<=bg3)
						{
							k=i+1+bg+bg2+max((long long)0,bg-(i-bg2-1));
						}
						else if(i<=y-1)
						{
							k=m+max((long long)0,bg-(i-bg2-1))+max((long long)0,bg2-(i-bg3-1));
						}
						else
						{
							k=max((long long)0,bg-(i-bg2-1))+max((long long)0,bg2-(i-bg3-1))+max((long long)0,bg-(i-y))+max((long long)0,bg3-(i-y));
						}
						if(fq[i]!=k)
						{
							bad=1;
							break;
						}
					}
				}
			}
			if(bad)
			{
				bad=0;
				n=bg2+bg3+1;
				y=bg3+1;
				if(t%n!=0)
				{
					bad=1;
				}
				else
				{
					m=t/n;
					x=m-bg;
					if(y+x-2!=mx||x-1<=bg||x<y)
					{
						bad=1;
					}
					else
					{
						for(i=1;i<=mx;i++)
						{
							if(i<=bg)
							{
								k=i*4;
							}
							else if(i<=bg2)
							{
								k=i*4-(i-bg)*2+1;
							}
							else if(i<=bg3)
							{
								k=i+1+bg+bg2+max((long long)0,bg-(i-bg2-1));
							}
							else if(i<=x-1)
							{
								k=n+max((long long)0,bg-(i-bg2-1))+max((long long)0,bg-(i-bg3-1));
							}
							else
							{
								k=max((long long)0,bg-(i-bg2-1))+max((long long)0,bg-(i-bg3-1))+max((long long)0,bg2-(i-x))+max((long long)0,bg3-(i-x));
							}
							if(fq[i]!=k)
							{
								bad=1;
								break;
							}
						}
					}
				}
			}
		}
	}
	else
	{
		bad=1;
	}
	if(bad)
	{
		printf("-1\n");
	}
	else
	{
		printf("%lld %lld\n%lld %lld\n",n,m,y,x);
	}
}