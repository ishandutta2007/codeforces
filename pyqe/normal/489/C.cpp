#include <iostream>

using namespace std;

int main()
{
	long long m,s,r,rr,i,ss;
	
	cin>>m>>s;
	if(m==1&&s==0)
	{
		cout<<"0 0\n";
	}
	else if(s>9*m||s==0)
	{
		cout<<"-1 -1\n";
	}
	else
	{
		rr=9*m-s;
		r=rr;
		i=0;
		if(r<9)
		{
			cout<<9-r;
			r=0;
		}
		else
		{
			cout<<"1";
			r-=8;
		}
		i++;
		while(r>9)
		{
			cout<<"0";
			r-=9;
			i++;
		}
		if(i<m)
		{
			cout<<9-r;
			r=0;
			i++;
			for(i=i;i<m;i++)
			{
				cout<<"9";
			}
		}
		cout<<" ";
		r=rr;
		ss=9*m;
		i=0;
		while(ss-r>9)
		{
			cout<<"9";
			ss-=9;
			i++;
		}
		cout<<ss-r;
		i++;
		for(i=i;i<m;i++)
		{
			cout<<"0";
		}
		cout<<"\n";
	}
}