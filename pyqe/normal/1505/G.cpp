#include <bits/stdc++.h>

using namespace std;

long long n;
string ky[26];

int main()
{
	long long i,j,k;
	string s;
	
	ky[0]="10010";
	ky[1]="11020";
	ky[2]="20011";
	ky[3]="21012";
	ky[4]="11011";
	ky[5]="21021";
	ky[6]="22022";
	ky[7]="12021";
	ky[8]="11011";
	ky[9]="12012";
	ky[10]="10120";
	ky[11]="11130";
	ky[12]="20121";
	ky[13]="21122";
	ky[14]="11121";
	ky[15]="21131";
	ky[16]="22132";
	ky[17]="12131";
	ky[18]="11121";
	ky[19]="12122";
	ky[20]="10221";
	ky[21]="11231";
	ky[22]="12113";
	ky[23]="20222";
	ky[24]="21223";
	ky[25]="11222";
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		s="";
		for(j=0;j<5;j++)
		{
			scanf("%lld",&k);
			s+=(char)(k+'0');
		}
		for(j=0;ky[j]!=s;j++);
		printf("%c",(char)j+'a');
	}
	printf("\n");
}