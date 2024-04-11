#include<cstdio>
#include<iostream>
using namespace std;

int l[5],r[5],s[5],p[5],flag;

int main()
{
	for(int i=1;i<=4;i++)
		scanf("%d%d%d%d",&l[i],&s[i],&r[i],&p[i]);
	if(l[1]&&p[4])
		flag=true;
	if(r[1]&&p[2])
		flag=true;
	if(s[1]&&p[3])
		flag=true;
	if(l[2]&&p[1])
		flag=true;
	if(r[2]&&p[3])
		flag=true;
	if(s[2]&&p[4])
		flag=true;
	if(l[3]&&p[2])
		flag=true;
	if(r[3]&&p[4])
		flag=true;
	if(s[3]&&p[1])
		flag=true;
	if(l[4]&&p[3])
		flag=true;
	if(r[4]&&p[1])
		flag=true;
	if(s[4]&&p[2])
		flag=true;
	for(int i=1;i<=4;i++)
		if((r[i]||s[i]||l[i])&&p[i])
			flag=true;
	if(flag)
		cout<<"YES";
	else
		cout<<"NO";
}