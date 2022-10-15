#include<bits/stdc++.h>
using namespace std;
 long long dig_sum(long long a)
{
    long long count1=0;
    while(a>0)
    {
        count1+=a%10;
        a/=10;
    }
    return count1;
}
int main()
{
    long long n,s;
    cin>>n>>s;
    long long l=1,r=n+1;
    while(l<r)
    {
        long long mid=(l+r)/2;
        long long b=dig_sum(mid);
        if(mid-b>=s)
            r=mid;
        else l=mid+1;
    }
    cout<<n-l+1<<endl;
}