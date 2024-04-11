#include <iostream>
#include <string.h>
using namespace std;
int res[105];
int main()
{
 	memset(res,0,sizeof(res));
 	 int n,m;
	 cin>>n>>m;
	 int num[105];
	 for(int i=1;i<=m;i++)
	 {
	  		 cin>>num[i];
	  		 for(int j=num[i];j<=n;j++)if(!res[j])res[j]=num[i];
	 }
	 for(int i=1;i<=n;i++)cout<<res[i]<<" ";
	 //system("pause");
	 return 0;
}