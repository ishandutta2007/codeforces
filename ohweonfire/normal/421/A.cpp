#include <iostream>
#include <cstdio>
using namespace std;
bool xx[101],y[101];
int x;
int main()
{
 	int n,a,b;
 	cin>>n>>a>>b;
 	while(a--){cin>>x;xx[x]=true;}
 	while(b--){cin>>x;y[x]=true;}
 	for(int i=1;i<=n;i++)
	{
	 		if(xx[i])putchar('1');else putchar('2');
	 		putchar(' ');
	}
	return 0;
}