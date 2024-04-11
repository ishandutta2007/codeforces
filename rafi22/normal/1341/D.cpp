#include <bits/stdc++.h>

using namespace std;

int DP[2007][2007];
int koszt[10];
string cyfry[10];
string tab[2007];

int main()
{
    for(int i=0;i<2003;i++)
    {
        for(int j=0;j<2003;j++)
        {
            DP[i][j]=-1;
        }
    }
    cyfry[0]="1110111";
    cyfry[1]="0010010";
    cyfry[2]="1011101";
    cyfry[3]="1011011";
    cyfry[4]="0111010";
    cyfry[5]="1101011";
    cyfry[6]="1101111";
    cyfry[7]="1010010";
    cyfry[8]="1111111";
    cyfry[9]="1111011";
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>tab[i];
    DP[n+1][0]=0;
    for(int i=n;i>0;i--)
    {
        for(int j=0;j<10;j++) koszt[j]=-1;
        for(int j=0;j<10;j++)
        {
            int p=0;
            bool b=1;
            for(int l=0;l<7;l++)
            {
                if(tab[i][l]=='1'&&cyfry[j][l]=='0') b=0;
                else if(tab[i][l]=='0'&&cyfry[j][l]=='1') p++;
            }
            if(b) koszt[p]=max(koszt[p],j);
        }
        //for(int j=0;j<=7;j++) cout<<koszt[j]<<" ";
        for(int j=0;j<=k;j++)
        {
            int maxi=-1;
            for(int l=0;l<=min(7,j);l++)
            {
                if(koszt[l]>-1)
                {
                    if(DP[i+1][j-l]>-1) maxi=max(maxi,koszt[l]);
                }
            }
            DP[i][j]=maxi;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<DP[i][k];
        if(DP[i][k]==-1) break;
        int p=0;
        for(int l=0;l<7;l++)
        {
            if(tab[i][l]=='0'&&cyfry[DP[i][k]][l]=='1') p++;
        }
        k-=p;
    }

    return 0;
}