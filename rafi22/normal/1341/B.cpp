#include <iostream>

using namespace std;
int pref[200007];
bool is[200007];

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,k;
        cin>>n>>k;
        int tab[n];

        for(int j=1;j<=n;j++) cin>>tab[j];
        for(int j=2;j<=n-1;j++)
        {
            if(tab[j-1]<tab[j]&&tab[j]>tab[j+1])
            {
                is[j]=1;

            }
        }

        for(int j=1;j<=n;j++)
        {
            pref[j]=pref[j-1];
            if(is[j]) pref[j]++;
            //cout<<pref[j]<<" ";
        }
       // cout<<endl;
        int maxi=-1,maxp;
        for(int j=1;j<=n-k+1;j++)
        {
            if(pref[k+j-2]-pref[j]>maxi)
            {
                maxi=pref[k+j-2]-pref[j];
                maxp=j;
            }
        }
        for(int i=0;i<n+7;i++)
        {
            pref[i]=0;
            is[i]=0;
        }
        cout<<maxi+1<<" "<<maxp<<endl;

    }
    return 0;
}