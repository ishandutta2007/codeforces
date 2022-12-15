#include <iostream>
using namespace std;
int cache[100][100],ans[100][100];
int check,m,n,cur;
int main() {
    cin >> m>>n;
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin >> cache[i][j];
            ans[i][j]=1;
        }
    }
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (cache[i][j]==0)
            {
                for (int k=0;k<n;k++) ans[i][k]=0;
                for (int k=0;k<m;k++) ans[k][j]=0;
            }
        }
    }
    check=1;
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            cur=0;
            for (int k=0;k<n;k++) if(ans[i][k]==1) cur=1;
            for (int k=0;k<m;k++) if(ans[k][j]==1) cur=1;
            if (cur!=cache[i][j]) check=0;
        }
    }
    if (check)
    {
        cout << "YES\n";
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++) cout << ans[i][j]<<' ';
            cout << '\n';
        }
    }
    else cout << "NO";
    return 0;
}