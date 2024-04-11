#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=600001;
int n,m,T; 
int q[N];

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

int main()
{
	int a=read(),b=read(),k=read();
	if (k==0) 
	{
		cout << "Yes\n";
		for (int i=1;i<=b;i++) cout << 1;
		for (int i=1;i<=a;i++) cout << 0;
		cout << endl;
		for (int i=1;i<=b;i++) cout << 1;
		for (int i=1;i<=a;i++) cout << 0;
		return 0;
	}
	if (a==0||b==1)
	{
		cout << "No\n";
		return 0;
	}
	if (k>a+b-2)
	{
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	int ans=a+b-2-k;
	cout << "1";
	int cnt=0;
	for (int i=1;i<a;i++) q[++cnt]=0;
	for (int i=1;i<=b-2;i++) q[++cnt]=1;
	for (int i=1;i<=ans;i++) cout << q[i];
	cout << "1";
	for (int i=ans+1;i<=cnt;i++) cout << q[i];
	cout << 0;
	cout << endl;
	cout << "1";
	for (int i=1;i<=ans;i++) cout << q[i];
	cout << "0";
	for (int i=ans+1;i<=cnt;i++) cout << q[i];
	cout << 1;
	return 0;
}

//1111111111110
//1011111111111
//