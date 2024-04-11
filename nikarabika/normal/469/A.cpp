#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[n+1];
    for(int i=1; i<=n; i++)
        A[i]=false;
    int p, q;
    cin>>p;
    for(int i=0; i<p; i++)
    {
        int t;
        cin>>t;
        A[t]=true;
    }
    cin>>q;
    for(int i=0; i<q; i++)
    {
        int t;
        cin>>t;
        A[t]=true;
    }

    for(int i=1; i<=n; i++)
    {
        if(!A[i])
        {
            cout<<"Oh, my keyboard!"<<endl;
            return 0;
        }
    }
    cout<<"I become the guy."<<endl;
    return 0;
}