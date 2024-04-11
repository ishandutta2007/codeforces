#include<bits/stdc++.h>
using namespace std;

int T,n;
string a,b;
string s="abacaba";

bool check(string a)
{
	int sum=0;
	for (int i=0;i+6<n;i++)
		{
			b=a;
			bool flag=1;
			for (int j=i;j<=i+6;j++)
				if (s[j-i]!=a[j])
					{flag=0;break;}
			if (flag)sum++;
		}
	return sum==1;
}

void print(string b)
{
	for (int i=0;i<n;i++)
		if (b[i]=='?')cout<<'d';
		else cout<<b[i];
	cout<<endl;
}

int main()
{
	cin>>T;
	while(T--)
	{
		a=b="";bool flag=0;
		cin>>n>>a;
		for (int i=0;i+6<n;i++)
		{
			b=a;
			for (int j=i;j<=i+6;j++)
				if (s[j-i]!=a[j])
					if (a[j]=='?')
						b[j]=s[j-i];
					else
						break;
			if (check(b)){cout<<"YES"<<endl;print(b);flag=1;break;}
		}
		if (!flag)cout<<"NO"<<endl;
	}
	return 0;
}