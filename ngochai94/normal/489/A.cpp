#include <bits/stdc++.h>
using namespace std;

int lis[3001];
int n,tmp,ind;
int main()
{
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin >>n;
    for (int i=0;i<n;i++) cin>> lis[i];
    cout << n-1<<endl;
    for (int i=0;i<n-1;i++)
    {
        tmp=1000000001;
        ind=-1;
        for (int j=i;j<n;j++)
        {
            if (lis[j]<tmp)
            {
                tmp=lis[j];
                ind=j;
            }
        }
        cout << i<<' '<<ind<<endl;
        lis[ind]=lis[i];
    }
    return 0;
}