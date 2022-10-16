#include <iostream>

using namespace std;

int main()
{
    int n; cin>>n;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    long long int res=0;
    int akt=a[n-1];
    res+=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        akt=min(akt-1,a[i]);
        akt=max(akt,0);
        res+=akt;
    }
    cout<<res;
    return 0;
}