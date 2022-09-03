#include <iostream>
using namespace std;
int main()
{
double sum;
int n;
cin>>n;
for(int i=0;i<n;i++){double x,y;cin>>x>>y;sum=sum+y;}
sum/=n;
sum+=5;
cout<<sum;
return 0;
}