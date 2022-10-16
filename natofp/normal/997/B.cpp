#include <iostream>

using namespace std;

int main()
{
    long long n;
    long long x=0;
    long long odp=0;
    cin>>n;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(i>=1 && j>=5) continue;
            odp+=max(x,n-i-j+1);
        }
    }
    cout<<odp;
    return 0;
}