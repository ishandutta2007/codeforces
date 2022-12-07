#include<bits/stdc++.h>
using namespace std;
string s1,a[5];
int main()
{
	cin>>s1>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
	for(int i=0;i<=4;i++)
		for(int j=0;j<=1;j++)
			if(s1[j]==a[i][j])
			{
				printf("YES\n");
				return 0;
			}
	printf("NO\n");
}