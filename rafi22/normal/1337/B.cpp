#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int j=0;j<t;j++)
    {
        int x,n,m;
        bool b=0;
        cin>>x>>n>>m;
        while(x/2+10<x&&n>0)
        {
            x=x/2+10;
            n--;
            if(x<=0)
            {
                b=1;
                break;
            }
        }
        while(m>0)
        {
            x-=10;
            if(x<=0)
            {
                b=1;
                break;
            }
            m--;
        }
        if(b) cout<<"Yes"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}