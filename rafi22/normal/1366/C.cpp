#include <iostream>

using namespace std;

char tab[37][37];

int ile1[2*37];
int ile0[2*37];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<=2*37;i++)
        {
            ile1[i]=0;
            ile0[i]=0;
        }
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>tab[i][j];
                if(tab[i][j]=='0') ile0[min(i+j,n-i+1+m-j+1)]++;
                else ile1[min(i+j,n-i+1+m-j+1)]++;
            }
        }
        int ans=0;
        for(int i=2;i<=(n+m)/2+(n+m)%2;i++)
        {
            ans+=min(ile0[i],ile1[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}