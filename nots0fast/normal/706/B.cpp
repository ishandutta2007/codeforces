#include <iostream>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> hamisi;
	for(int i=0; i<n; i++)
	{
		int eded;
		cin>>eded;
		hamisi.push_back(eded);
	}
	sort(hamisi.begin(),hamisi.end());
	int ko;
	cin>>ko;
	for(int i=0; i<ko; i++)
	{
		int q;
		cin>>q;
		int bas = 0;
		int son = n-1;
		bool John = true;
		int c;
		while(John)
		{
			 c = (bas+son)/2;
			 if(bas==son-1 || bas==son)
			 {
			 	John=false;
			 	if(hamisi[son]<=q)
			 	{
			 		c=son+1;
				}
				else if(hamisi[bas]<=q)
				{
					c=bas+1;
				}
				else
				{
					c=bas;
				}
			 }
			else if( (c==0 || hamisi[c-1]<=q) && hamisi[c]>q)
			{
				John=false;
			}
			else if(hamisi[c]<=q)
			{
				bas=c;
			}
			else
			{
				son=c;
			}
		}
		cout<<c<<endl;
	}
}