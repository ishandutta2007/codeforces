#include <iostream>

using namespace std;

int main()
{
    int n,a,b,arr[100][100],i,j,k;

    cin >> n >> a >> b;

    for (i=0;i<a;i++)
    {
        for (j=0;j<b;j++) arr[i][j]=0;
    }

    if (a*b<n) cout << "-1";
    else
    {
        k=1;
        for (i=0;i<a;i++)
        {
            for (j=0;j<b;j++)
            {
                if (k<=n) {
                if (i % 2 == 0) arr[i][j]=k;
                if (i % 2 == 1) arr[i][b-j-1]=k;
                k++;
                }
            }
        }
         for (i=0;i<a;i++)
    {
        for (j=0;j<b;j++) cout << arr[i][j] << " ";
        cout << endl;
    }
    }




    return 0;
}