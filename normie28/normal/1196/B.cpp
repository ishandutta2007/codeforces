#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	int64_t x,y,z,n,t,t1,k,fla,i,j,m,count,min,a[200001],tar; 
	cin>>t;
	for (t1=1;t1<=t;t1++)
	{
	cin>>n>>k; count=0; 
	for (i=1;i<=n;i++)
	{cin>>x; if (x%2) {count++;a[count]=i;}}
	if ((count<k)or((count%2==1)and(k%2==0))or((count%2==0)and(k%2==1))) cout<<"NO"<<endl; else {
	cout<<"YES"<<endl;
	for (i=1;i<=k-1;i++) cout<<a[i]<<' '; cout<<n<<endl;
}
}
}