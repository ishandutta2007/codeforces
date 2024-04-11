#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    int max_=0;
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++)
    {
        int s=0;
        for(int j=i; j<n; j++)
        {
            s ^= a[j];
            if(s>max_)
                max_=s;
        }
    }
    cout<<max_<<endl;
    return 0;
}