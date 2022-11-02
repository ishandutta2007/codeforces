#include<bits/stdc++.h>
#define MAXN 200007
using namespace std;
int n;
long long a[MAXN];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long sol=0;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=1;i<n;i++) sol+=max(0LL,a[i-1]-a[i]);
        cout<<sol<<"\n";
    }
}