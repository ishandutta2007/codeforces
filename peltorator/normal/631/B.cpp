#include <iostream>

using namespace std;

int main()
{
    int n,m,k,a[100001][3],b[100001][3],x,y,z;
    cin >> n >> m >> k;
    for (int i=0;i<n+m+5;i++)
    {
        a[i][1]=0;
        a[i][2]=-1;
        b[i][1]=0;
        b[i][2]=-1;
    }
    for (int i=1; i<=k;i++)
    {
        cin >> x >> y >> z;
        if (x==1)
        {
            a[y][1]=z;
            a[y][2]=i;
        }
        if (x==2)
        {
            b[y][1]=z;
            b[y][2]=i;
        }

    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if(a[i][2]>b[j][2]) cout << a[i][1] << " ";
            else cout << b[j][1] << " ";
        }
        cout << endl;
    }

    return 0;
}