#include <iostream>
#include <string.h>
using namespace std;
int s[105][205],t,n,m1;
bool judge(int m)
{
 	 for(int i=m;i<=t;i+=m)for(int j=1;j<=m/2;j++)for(int k=1;k<=m1;k++)if(s[i-m+j][k]!=s[i-j+1][k])return false;
 	 return true;
}
int main()
{
 	cin>>n>>m1;
 	t=n;
 	for(int i=1;i<=n;i++)for(int j=1;j<=m1;j++)cin>>s[i][j];
 	while(n/2*2==n&&judge(n))n/=2;
 	cout<<n<<endl;
 	//system("pause");
 	return 0;
}