#include <bits/stdc++.h>
using namespace std;
int main()
{ int t;
cin>>t;
while(t--)
{ int n;
cin>>n;
long long int arr[n],a=0,b=0,m=0,m1=0;
for(int i=0;i<n;i++)
{ cin>>arr[i];
if(i%2==0)
a+=arr[i];
}
for(int i=0;i<n-1;i+=2)
{ b+=arr[i+1]-arr[i];
m=max(m,b);
if(b<0)
b=0;}
b=0;
for(int i=1;i<n-1;i+=2)
{ b+=arr[i]-arr[i+1];
m1=max(m1,b);
if(b<0)
b=0;}
cout<<a+max(m,m1)<<endl;}}