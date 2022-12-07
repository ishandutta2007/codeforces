#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,k,s;
    cin>>n>>k>>s;
    
    if(s<k)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    
    long long int max = (n-1) * k;
    if(s>max)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    
    long long int avg = s/k;
    long long int add = s%k;
    
    long long int last = add%2;
    add = add/2;
    
    for(long long int i=0;i<add;i++)
    {
        cout<<avg+2<<" 1 ";
        k-=2;
    }
    long long int cur = 1;
    long long int next = avg+1;
    if(last)
    {
        cout<<avg+2<<" ";
        cur = avg+2;
        next = 2;
        k--;
    }
    while(k>0)
    {
        cout<<next<<" ";
        long long int temp = next;
        next = cur;
        cur = temp;
        k--;
    }
    
    return 0;
}