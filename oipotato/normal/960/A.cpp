#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int num[330];
string s;
int main()
{
	cin>>s;
	char now='a';
	for(auto j:s)
	{
		if(j!=now&&(j>'c'||j!=now+1)){puts("NO");return 0;}
		else if(j!=now){now=j;num[now]=1;}
		else num[now]++;
	}
	if((num['c']!=num['a']&&num['c']!=num['b'])||!num['a']||!num['b'])puts("NO");
	else puts("YES");
	return 0;
}