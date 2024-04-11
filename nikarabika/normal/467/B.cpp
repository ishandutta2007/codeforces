#include <iostream>

using namespace std;

typedef     unsigned long long int      ull;

int main()
{
    int m, n, k;
    cin>>n>>m>>k;
    int res=0;
    bool s[m+1][n];
    for(int i=0; i<=m; i++)
    {
        ull t;
        cin>>t;
        int j=0;
        while(j<n)
        {
            s[i][j]=t&1;
            t/=2;
            j++;
        }
    }
    for(int i=0; i<m; i++)
    {
        int c=0;
        for(int j=0; j<n; j++)
            if(s[i][j]!=s[m][j])
                c++;
        if(c<=k)
            res++;
    }
    cout<<res<<endl;
    return 0;
}