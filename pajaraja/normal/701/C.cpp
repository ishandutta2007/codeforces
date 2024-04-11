#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;
int p[2][26];
bool e[2][26];
int main(int argc, char** argv) 
{
	for(int i=0;i<26;i++)
	{
		p[0][i]=0;
		p[1][i]=0;
		e[0][i]=false;
		e[1][i]=false;
	}
	int min=2222222,n,t,p1=-1,p2=-1;
	string s;
	bool o=false;
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		t=s[i];
		if(t-'a'<26&&t-'a'>=0) e[0][t-'a']=true;
		else e[1][t-'A']=true;
		
	}
	while(!o)
	{
		p2++;
		t=s[p2];
		if(t-'a'<26&&t-'a'>=0) p[0][t-'a']++;
		else p[1][t-'A']++;
		o=true;
		for(int i=0;i<26;i++) for(int j=0;j<2;j++) o=o&&((!e[j][i]&&p[j][i]==0)||(e[j][i]&&p[j][i]>0));
	}
	min=p2+1;
	while(p2<n)
	{
		while(o)
		{
		p1++;
		t=s[p1];
		if(t-'a'<26&&t-'a'>=0) p[0][t-'a']--;
		else p[1][t-'A']--;
		o=true;
		for(int i=0;i<26;i++) for(int j=0;j<2;j++) o=o&&((!e[j][i]&&p[j][i]==0)||(e[j][i]&&p[j][i]>0));
		}
		min=fmin(min,p2-p1+1);
		p2++;
		if(p2!=n) t=s[p2];
		if(t-'a'<26&&t-'a'>=0) p[0][t-'a']++;
		else p[1][t-'A']++;
		o=true;
		for(int i=0;i<26;i++) for(int j=0;j<2;j++) o=o&&((!e[j][i]&&p[j][i]==0)||(e[j][i]&&p[j][i]>0));
	}
	printf("%d",min);
	return 0;
}