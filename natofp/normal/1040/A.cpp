#include <iostream>

using namespace std;

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    int * tab;
    int w=0;
    tab=new int[n];
    for(int i=0;i<n;i++) cin>>tab[i];
    for(int i=0;i<n/2;i++)
    {
        if(tab[i]!=2 && tab[n-i-1]!=2 && tab[i]!=tab[n-i-1]) {cout<<"-1"; return 0;}
        else if(tab[i]!=tab[n-i-1])
        {
            if(tab[i]==2)
            {
                if(tab[n-i-1]==0) w+=a;
                else if(tab[n-i-1]==1) w+=b;


            }
            else if(tab[i]==0) w+=a;
            else w+=b;

        }
        else
        {
            if(tab[i]==2) w+=2*min(a,b);

        }
    }
    if(n%2==1)
    {
        if(tab[n/2]==2) w+=min(a,b);
    }
    cout<<w;
    return 0;
}