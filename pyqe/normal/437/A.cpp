#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long sq[2],zs=0;
pair<long long,long long> a[4];

int main()
{
	long long i;
	string s;
	
	for(i=0;i<4;i++)
	{
		cin>>s;
		a[i]={s.length()-2,i};
	}
	sort(a,a+4);
	if(a[0].fr*2<=a[1].fr)
	{
		sq[zs]=a[0].sc;
		zs++;
	}
	if(a[2].fr*2<=a[3].fr)
	{
		sq[zs]=a[3].sc;
		zs++;
	}
	if(zs==1)
	{
		printf("%c\n",(char)sq[0]+'A');
	}
	else
	{
		printf("C\n");
	}
}