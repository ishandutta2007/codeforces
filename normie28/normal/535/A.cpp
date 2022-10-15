#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	long long x,y,z,max,min,i,j,countu,countd;

	const string s[10]={"zero","one","two","three","four","five","six","seven","eight","nine"},a[10]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	cin>>x;
	if (x<10) cout<<s[x]; 
else if (x==10) cout<<"ten";
else if (x==11) cout<<"eleven";
else if (x==12) cout<<"twelve";
else if (x==13) cout<<"thirteen";
else if (x==14) cout<<"fourteen";
else if (x==15) cout<<"fifteen";
else if (x==16) cout<<"sixteen";
else if (x==17) cout<<"seventeen";
else if (x==18) cout<<"eighteen";
else if (x==19) cout<<"nineteen";
else if (x%10==0) cout<<a[x/10]; else cout<<a[x/10]<<'-'<<s[x%10];
}