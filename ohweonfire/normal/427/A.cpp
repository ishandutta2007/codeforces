#include<iostream>
using namespace std;
int main()
{
int people=0;
int res=0;
int n;
cin>>n;
while(n--)
{
int x;
cin>>x;
if(x!=-1)people+=x;
else if(people!=0)people--;else res++;
}
cout<<res<<endl;
return 0;
}