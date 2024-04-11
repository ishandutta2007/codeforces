#include <iostream>

using namespace std;

int main()
{
    int n, s;
    cin>>n>>s;
    int mug[n];
    {
            int sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>mug[i];
            sum+=mug[i];
        }
        if(sum<=s)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    for(int i=0; i<n; i++)
    {
        int sum=0;
        for(int j=0; j<n; j++)
        {
            sum+=mug[j];
        }
        sum-=mug[i];
        if(sum<=s)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}