#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	long long n,m,i,j,minn,maxx,countp=0,counts=0; string s1,s2,s3; vector<long long> a;
	while (cin>>s1) a.push_back(s1[0]-48+s1[1]*10);
	sort(a.begin(),a.end());
//	cout<<a[0]<<' '<<a[1]<<' '<<a[2]<<endl;
	if (abs(a[0]-a[1])==1) counts++; 
	if (abs(a[1]-a[2])==1) counts++; 
	if (abs(a[0]-a[2])==2) counts++;
	if ((abs(a[0]-a[1])==2)and(!(((a[0]+a[1])%10==0)and((a[0]*a[1])%10==9)))) counts++; 
	if ((abs(a[1]-a[2])==2)and(!(((a[1]+a[2])%10==0)and((a[1]*a[2])%10==9)))) counts++;  
	if (a[0]==a[1]) countp++; 
	if (a[0]==a[2]) countp++; 
	if (a[2]==a[1]) countp++;
//	cout<<countp<<' '<<counts<<endl;
	if ((counts==3)or(countp==3)) cout<<0; else 
	if ((counts==1)or(countp==1)or(counts==2)) cout<<1; else cout<<2; 
}