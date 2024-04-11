#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    char x, y;
    cin>>x;
    for(int i=1; i<m; i++)
    {
        cin>>y;
        if(y!=x)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    for(int i=1; i<n; i++)
    {
        char c, d;
        cin>>c;
        if(c==x)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        for(int j=1; j<m; j++)
        {
            cin>>d;
            if(d!=c)
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        x=c;
    }
    cout<<"YES"<<endl;
    return 0;
}