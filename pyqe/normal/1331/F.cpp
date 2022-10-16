#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<100069> dp;
string ky[118]={"H","HE","LI","BE","B","C","N","O","F","NE","NA","MG","AL","SI","P","S","CL","AR","K","CA","SC","TI","V","CR","MN","FE","CO","NI","CU","ZN","GA","GE","AS","SE","BR","KR","RB","SR","Y","ZR","NB","MO","TC","RU","RH","PD","AG","CD","IN","SN","SB","TE","I","XE","CS","BA","LA","CE","PR","ND","PM","SM","EU","GD","TB","DY","HO","ER","TM","YB","LU","HF","TA","W","RE","OS","IR","PT","AU","HG","TL","PB","BI","PO","AT","RN","FR","RA","AC","TH","PA","U","NP","PU","AM","CM","BK","CF","ES","FM","MD","NO","LR","RF","DB","SG","BH","HS","MT","DS","RG","CN","NH","FL","MC","LV","TS","OG"};

int main()
{
	long long i,j,ln;
	string s;
	
	cin>>s;
	n=s.length();
	dp[0]=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<118;j++)
		{
			ln=ky[j].length();
			if(s.substr(i,ln)==ky[j])
			{
				dp[i+ln]=dp[i+ln]|dp[i];
			}
		}
	}
	if(dp[n])
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}