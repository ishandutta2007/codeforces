#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
int a[5],d[]={1,1,2,7,4};
long long ans=99999999999999;
for(int i=0;i<5;i++){cin>>a[i];a[i]/=d[i];if(ans>a[i])ans=a[i];}
cout<<ans;
return  0;
}