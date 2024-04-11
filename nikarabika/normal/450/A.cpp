#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    int a[n];
    int max_=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        a[i]=(a[i]-1)/m;
        if(a[i]>max_)
            max_=a[i];
    }
    for(int i=n-1; i>=0; i--)
    {
        if(a[i]==max_)
        {
            cout<<i+1<<endl;
            return 0;
        }
    }
    return 0;
}