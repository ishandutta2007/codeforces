#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int M=20;
char a[M],b[M];

int main()
{
	cin>>a>>b;
	sort(a,a+strlen(a));
	for (int i=0;i<strlen(a);i++)
		if (a[i]!='0')
			{swap(a[i],a[0]);break;}
	ll sa=0,sb=0;
	for (int i=0;i<strlen(a);i++)
		sa=sa*10+a[i]-'0';
	for (int i=0;i<strlen(b);i++)
		sb=sb*10+b[i]-'0';
	if (sa!=sb)cout<<"WRONG_ANSWER";
	else if (b[0]=='0'&&sa!=0||sa==0&&b[1]=='0')cout<<"WRONG_ANSWER";
	else cout<<"OK";
	return 0;
}