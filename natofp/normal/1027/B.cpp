#include <iostream>

using namespace std;


int main()
{
    long long n,q;
    cin>>n>>q;
    for(int i=0;i<q;i++)
    {
        long long int x,y;
        cin>>x>>y;
        long long int odp=(x-1)*n+y;
        odp++;
        odp/=2;
        if(x%2!=y%2) odp+=((n*n+1)/2);
        cout<<odp<<endl;

    }
    return 0;
}