#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    bool a[n];
    for(int i=0; i<n; i++)
        a[i]=false;
    for(int i=0; i<n-1; i++)
    {
        int x;
        cin>>x;
        a[x-1]=true;
    }
    for(int i=0; i<n; i++)
        if(!a[i])
            cout<<i+1<<endl;
    return 0;
}