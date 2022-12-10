#include <iostream>

using namespace std;

int main()
{
    int n, m;
    unsigned long long int result=0;
    cin>>n>>m;
    unsigned long long int a, b;
    a=1;
    b=1;
    for(int i=0; i<m; i++)
    {
        cin>>b;
        if(b<a)
            result+=(n-a)+b;
        else
            result+=b-a;
        a=b;
    }
    cout<<result<<endl;
    return 0;
}