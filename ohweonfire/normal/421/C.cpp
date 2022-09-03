
#include <iostream>
using namespace std;
const int maxn=1e5+5;
char c[maxn];
int n,m,a[maxn],sum;
bool online[maxn],ans[maxn];
int main()
{
 	cin>>n>>m;
 	for(int i=0;i<m;i++)cin>>c[i]>>a[i];
 	for(int i=0;i<m;i++){if(c[i]=='-'&&!online[a[i]])
			sum++;
			online[a[i]]=true;}
	for(int i=0;i<m;i++)
	{
	 		
	 		if(c[i]=='+')
	 		{
			 			 if((i && a[i]!=a[i-1]) || sum)ans[a[i]]=true;
			 			 sum++;
			}
			else
			{
			 	sum--;
			 	if((i<m-1&&a[i]!=a[i+1])||sum)ans[a[i]]=true;
			}
	}
	sum=0;
	for(int i=1;i<=n;i++)sum+=(!ans[i]);
	cout<<sum<<endl;
	for(int i=1;i<=n;i++)if(!ans[i])cout<<i<<' ';
	return 0;
}