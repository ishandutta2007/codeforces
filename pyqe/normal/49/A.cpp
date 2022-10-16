#include <bits/stdc++.h>

using namespace std;

bitset<100069> spc;

int main()
{
	char ch,ch2,ch3;
	
	spc['a']=1;
	spc['e']=1;
	spc['i']=1;
	spc['o']=1;
	spc['u']=1;
	spc['y']=1;
	spc['A']=1;
	spc['E']=1;
	spc['I']=1;
	spc['O']=1;
	spc['U']=1;
	spc['Y']=1;
	for(;scanf(" %c",&ch)==1;ch3=ch2,ch2=ch);
	if(spc[ch3])
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}