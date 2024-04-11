#include <iostream>
using namespace std;
 
int main() {
	int n;
	cin>>n;
	long long tab[n],ans=0;
	for(int i=0;i<n;i++) cin>>tab[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				ans=max(ans,tab[i]|tab[j]|tab[k]);
			}
		}
	}
	cout<<ans;
	return 0;
}