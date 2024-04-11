#include <bits/stdc++.h>

using namespace std;

short n,bg[2][169],a[169];
map<deque<short>,queue<short>> vl;
deque<short> dq;
bitset<269> sq,vtd;

void ad(short x)
{
	if(vl[dq].empty())
	{
		return;
	}
	short k=vl[dq].front();
	
	sq[k]=x;
	vtd[k]=1;
	vl[dq].pop();
	vl[dq].push(k);
}

int main()
{
	short i,j,ii,iii,ln,k,c=0;
	string s;
	
	scanf("%hu",&n);
	for(i=1;i<=n*2-2;i++)
	{
		cin>>s;
		ln=s.length();
		dq.clear();
		for(j=1;j<=ln;j++)
		{
			k=s[j-1]-'a';
			dq.push_back(k);
			if(ln==n-1)
			{
				bg[c][j]=k;
			}
		}
		vl[dq].push(i);
		c+=ln==n-1;
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			if(i<=n-1)
			{
				a[i]=bg[ii][i];
			}
			else
			{
				a[i]=bg[!ii][i-1];
			}
		}
		vtd.reset();
		dq.clear();
		for(i=1;i<=n-1;i++)
		{
			dq.push_back(a[i]);
			ad(0);
		}
		dq.clear();
		for(i=n;i-1;i--)
		{
			dq.push_front(a[i]);
			ad(1);
		}
		for(i=1;i<=n*2-2;i++)
		{
			if(!vtd[i])
			{
				i=-1;
				break;
			}
		}
		if(i!=-1)
		{
			for(i=1;i<=n*2-2;i++)
			{
				printf("%c","PS"[sq[i]]);
			}
			printf("\n");
			return 0;
		}
	}
}