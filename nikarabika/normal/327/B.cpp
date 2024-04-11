#include <iostream>

using namespace std;

bool isprime(int n)
{
    for(int i=2; i*i<=n; i++)
        if(n%i==0)
            return false;
    return true;
}

int main()
{
    int n;
    cin>>n;
    int a=1;
    int i=1;
    while(1 && i<=n)
    {
        a++;
        if(isprime(a))
        {
            cout<<a<<' ';
            i++;
        }
    }
    return 0;
}