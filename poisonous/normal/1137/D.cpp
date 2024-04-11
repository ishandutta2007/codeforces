#include<bits/stdc++.h>
using namespace std;
string s[15];
int main()
{
	int x=0,y=0,z=0,now=0,o=0;
	while(1)
	{
		y++;
		if(now)
		{
			
			cout<<"next 0 1\n";
		}
		else
		{
			z++;
			cout<<"next 0\n";
		}
		cout.flush();
		now^=1;
		int t;
		scanf("%d",&t);
		for(int i=0;i<t;i++)
			cin>>s[i];
		if(t==2)
			if(o)
				break;
			else
				o=1;
	}
	while(1)
	{
		cout<<"next 1 9\n";
		cout.flush();
		int t;
		int can=0;
		scanf("%d",&t);
		for(int i=0;i<t;i++)
		{
			int v=0;
			cin>>s[i];
			for(int j=0;j<s[i].length();j++)
				if(s[i][j]=='0')
					v=1;
				else
					if(s[i][j]=='1'&&v==1)
						can=1;
		}
		if(can)
			break;
	}
	int pt;
	while(1)
	{
		cout<<"next 2 3 4 5 6 7 8 9\n";
		cout.flush();
		int t;
		int can=0;
		scanf("%d",&t);
		for(int i=0;i<t;i++)
		{
			int v=0;
			cin>>s[i];
			for(int j=0;j<s[i].length();j++)
				if(s[i][j]=='2')
					v=1;
				else
					if(s[i][j]=='9'&&v==1)
						can=1;
		}
		pt=t;
		if(can)
			break;
	}
	while(1)
	{
		if(pt==1)
			break;
		cout<<"next 0 1\n";
		cout.flush();
		int t;
		scanf("%d",&t);
		for(int i=0;i<t;i++)
			cin>>s[i];
		pt=t;		
	}
	cout<<"done\n";
	cout.flush();
}