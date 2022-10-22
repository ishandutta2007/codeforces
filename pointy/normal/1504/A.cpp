#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=400001;
int n,m,T; 
char a[N];

inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 

void work()
{
	cin >> a;
	int len=strlen(a),flag=0;
	for (int i=0;i<len;i++)
	{
		if (a[i]!='a') flag=1;
	}
	if (flag==0)
	{
		puts("NO");
		return;
	}
	puts("YES");
	if (a[len-1]!='a') 
	{
		cout << "a" << a ;
		cout << endl;
		return;
	}
	for (int i=0;i<len-1;i++)
	{
		if (a[i]!=a[len-i-2]) 
		{
			cout << "a" << a ;
			cout << endl;
			return;	
		}
	}
	cout << a << "a";
	cout << endl;
	return;
}

int main()
{
	T=read();
	while (T--)
	{
		work();
	}
	return 0;
}