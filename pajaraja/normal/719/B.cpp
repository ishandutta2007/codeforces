#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, char** argv) 
{
	int n,k[2][2],t;
	k[0][0]=k[1][0]=k[0][1]=k[1][1]=0;
	string s;
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='r') t=1;
		else t=0;
		k[i%2][t]++;
	}
	int rn,rp;
	rn=max(k[0][1],k[1][0]);
	rp=max(k[0][0],k[1][1]);
	int r=min(rn,rp);
	printf("%d",r);
	return 0;
}