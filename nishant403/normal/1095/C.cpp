#include <bits/stdc++.h>
using namespace std;
int main()
{

long n,k;
cin >> n >> k;

long count=0;
long temp=n;
long a[33]={0};
long counter=0;
long powers[33];

powers[0]=1;

for(long i=1;i<33;i++)
{
 powers[i]=2*powers[i-1];   

}


while(temp!=0)
{

    if(temp%2==1)
    {
        count++;
        a[counter]=1;
    }
    temp=temp/2;
    counter++;
}

long divisons=k-count;


if(k < count || k > n) cout <<"NO\n";

else
{

if(divisons)
for(long i=32;i>=1;i--)
{
    if(a[i]<divisons)
    {
        a[i-1]+=(2*a[i]);
        divisons-=a[i];
        a[i]=0;
        
    }
    else
    {
        a[i-1]+=(2*divisons);
        a[i]=a[i]-divisons;
        divisons=0;
        break;
    }
}

cout << "YES\n";

for(long i=0;i<33;i++)
{
for(long j=0;j<a[i];j++)
cout << powers[i] << " ";
}


}


return 0;
}