#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int sum1=0, sum2=0;
    for(int i=0; i<n/2; i++)
    {
        char c;
        cin>>c;
        if(c!='7' && c!='4')
        {
            cout<<"NO"<<endl;
            return 0;
        }
        c-=48;
        sum1+=c;
    }
    for(int i=0; i<n/2; i++)
    {
        char c;
        cin>>c;
        if(c!='7' && c!='4')
        {
            cout<<"NO"<<endl;
            return 0;
        }
        c-=48;
        sum2+=c;
    }
    if(sum2!=sum1)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}