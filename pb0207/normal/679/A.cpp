#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int a[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49};

string s;

int main()
{
	int cnt=0;
	for(int i=0;i<19;i++)
	{
		printf("%d\n",a[i]);
		fflush(stdout);
		cin>>s;
		if(s=="yes")
			cnt++;
		else
			continue;
	}
	if(cnt>=2)
		puts("composite");
	else
		puts("prime");
	fflush(stdout);
} 
//s'ta'k'i'o'istakioi