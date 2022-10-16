#include <iostream>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long int lli;
int main()
{
	 vector<long long int> hamisi;
	 long long int n;
	 cin>>n;
	 for(int i=0; i<n; i++)
	 {
	 	long long int eded;
	 	cin>>eded;
	 	hamisi.push_back(eded);
	 }
	 sort(hamisi.begin(),hamisi.end());
	 long long int cem = 0;
	 for(int i=1; i<hamisi.size(); i++)
	 {
	 	if(i==1)
	 	cem=hamisi[i]-hamisi[0];
	 	else
	 	cem+=hamisi[i]-hamisi[0];
	 }
	 long long int min = cem;
	 long long int lazim = hamisi[0];
	 for(int i=1; i<hamisi.size(); i++)
	 {
	 	cem-=(n-1-i)*(hamisi[i]-hamisi[i-1]);
	 	cem+=(i-1)*(hamisi[i]-hamisi[i-1]);
	 	if(cem<min)
	 	{
	 		min =cem;
	 		lazim = hamisi[i];
		}
	 }
	 cout<<lazim<<endl;
}