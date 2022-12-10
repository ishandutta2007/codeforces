#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    //char a[n][m];



    for(int i=0; i<n; i++)
    {
        int ii=i;
        for(int j=0; j<m; j++)
        {
            ii++;
            char x;
            cin>>x;
            if(x=='.')
            {
                if(ii%2==0)
                    cout<<'W';
                else
                    cout<<'B';
            }
            else
                cout<<x;
        }
        cout<<endl;
    }

    return 0;
}