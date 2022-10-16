#include <bits/stdc++.h>

using namespace std;

const int mm=6,d=18,prt=3,dv=998244353;
int n[2],nn,pc[(1<<d)+1],a[2][125069],ca[2][1<<d],dsu[mm],cc[mm],pwk;
bitset<mm> am[125069][mm];

int pw(int x,int y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=(long long)pwk*pwk%dv;
	if(y%2)
	{
		pwk=(long long)pwk*x%dv;
	}
	return pwk;
}

inline void fft(int sz,int pa[],bool iv)
{
	int i,j,r,k,l,p;
	
	for(i=0;i<sz;i++)
	{
		k=0;
		for(j=0;1<<j<sz;j++)
		{
			k=k<<1|i>>j&1;
		}
		if(k>i)
		{
			swap(pa[i],pa[k]);
		}
	}
	for(i=1;1<<i<=sz;i++)
	{
		for(j=0;j<sz;j+=1<<i)
		{
			for(r=0;r<1<<i-1;r++)
			{
				k=pa[j+r];
				l=pa[j+r+(1<<i-1)];
				p=r<<d-i;
				if(iv)
				{
					p=(1<<d)-p;
				}
				l=(long long)l*pc[p]%dv;
				pa[j+r]+=l;
				if(pa[j+r]>=dv)
				{
					pa[j+r]-=dv;
				}
				pa[j+r+(1<<i-1)]=k-l;
				if(pa[j+r+(1<<i-1)]<0)
				{
					pa[j+r+(1<<i-1)]+=dv;
				}
			}
		}
	}
	if(iv)
	{
		k=pw(sz,dv-2);
		for(i=0;i<sz;i++)
		{
			pa[i]=(long long)pa[i]*k%dv;
		}
	}
}

int fd(int x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i,j,r,ii,k,z;
	string s;
	
	k=pw(prt,dv-1>>d);
	pc[0]=1;
	for(i=1;i<=1<<d;i++)
	{
		pc[i]=(long long)pc[i-1]*k%dv;
	}
	for(ii=0;ii<2;ii++)
	{
		cin>>s;
		n[ii]=s.length();
		for(i=0;i<n[ii];i++)
		{
			a[ii][i]=s[i]-'a';
		}
	}
	for(nn=1;nn<=n[0]-1+n[1]-1;nn<<=1);
	for(i=0;i<mm;i++)
	{
		for(j=0;j<mm;j++)
		{
			if(i!=j)
			{
				for(ii=0;ii<2;ii++)
				{
					for(r=0;r<nn;r++)
					{
						ca[ii][r]=r<n[ii]&&a[ii][r]==i;
					}
					swap(i,j);
				}
				for(r=0;r<n[1]-1-r;r++)
				{
					swap(ca[1][r],ca[1][n[1]-1-r]);
				}
				for(ii=0;ii<2;ii++)
				{
					fft(nn,ca[ii],0);
				}
				for(r=0;r<nn;r++)
				{
					ca[0][r]=(long long)ca[0][r]*ca[1][r]%dv;
				}
				fft(nn,ca[0],1);
				for(r=1;r<=n[0]-n[1]+1;r++)
				{
					am[r][i][j]=!!ca[0][n[1]-1+r-1];
				}
			}
		}
	}
	for(i=1;i<=n[0]-n[1]+1;i++)
	{
		for(j=0;j<mm;j++)
		{
			dsu[j]=j;
			cc[j]=1;
		}
		for(j=0;j<mm;j++)
		{
			for(r=0;r<mm;r++)
			{
				if(am[i][j][r]&&fd(j)!=fd(r))
				{
					cc[fd(j)]+=cc[fd(r)];
					dsu[fd(r)]=fd(j);
				}
			}
		}
		z=0;
		for(j=0;j<mm;j++)
		{
			if(fd(j)==j)
			{
				z+=cc[j]-1;
			}
		}
		cout<<z<<" \n"[i==n[0]-n[1]+1];
	}
}