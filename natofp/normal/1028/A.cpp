#include <iostream>
#include <bits/stdc++.h>



using namespace std;

char plansza[200][200];
void zeruj()
{
    for(int i=0;i<200;i++)
    {
        for(int j=0;j<200;j++)
        {
            plansza[i][j]='X';
        }
    }
}

int main()
{
    int n; int m;
    cin>>n>>m;
    zeruj();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>plansza[i][j];
        }
    }
    int a,b;
    bool xd=true;
   for(a=1;a<=n;a++)
   {

       {
            for(b=1;b<=m;b++)
                {
                    if(plansza[a][b]=='B') {xd=false; break;}
                }
       }
       if(xd==false) break;

   }
   int i=1;
   int k=a;
   while(plansza[a+1][b]=='B') {i++; a++;}
   cout<<k+(i/2)<<" "<<b+(i/2);
    return 0;
}