#include <iostream>

using namespace std;

int main()
{
    int n, d;
    cin>>n>>d;
    int t[n];
    int temp_1=0;
    for(int i=0; i<n; i++)
    {
        cin>>t[i];
        temp_1+=t[i]+10;
    }
    temp_1-=10;
    if(temp_1>d)
        cout<<-1<<endl;
    else
        cout<<2*(n-1)+((d-temp_1)/5)<<endl;
    return 0;
}