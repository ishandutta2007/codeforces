#include <bits/stdc++.h>
using namespace std;


int x,y;
int min(int a, int b)
{
	if(a>b)
		return b;
	return a;
}
int ciel()
{
	if(y<2)
		return 0;
	if(x>=2)
	{
		x-=2;
		y-=2;
		return 1;
	}
	else if(x==1)
	{
		if(y>=12)
		{
			y-=12;
			x-=1;
			return 1;
		}
		return 0;
	}
	else
	{
		if(y>=22)
		{
			y-=22;
			return 1;
		}
		return 0;
	}
}

int hanako()
{
	if(y>=22)
	{
		y-=22;
		return 1;
	}
	else if(y>=12)
	{
		if(x>=1)
		{
			x-=1;
			y-=12;
			return 1;
		}
		else
			return 0;

	}
	else if(y>=2)
	{
		if(x>=2)
		{
			x-=2;
			y-=2;
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>x>>y;

    int a = min(x/2, y/24);
    x-= a*2;
    y-= a*24;

    while(1)
    {
    	if(!ciel())
    	{
    		cout<<"Hanako"<<endl;
    		return 0;
    	}
    	if(!hanako())
    	{
    		cout<<"Ciel"<<endl;
    		return 0;
    	}

    }
    
    return 0;
}