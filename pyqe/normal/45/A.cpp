#include <bits/stdc++.h>

using namespace std;

string ky[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
map<string,long long> yk;

int main()
{
	long long i,k;
	string s;
	
	for(i=0;i<12;i++)
	{
		yk[ky[i]]=i;
	}
	cin>>s;
	scanf("%lld",&k);
	printf("%s\n",ky[(yk[s]+k)%12].c_str());
}