#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,k,t,t1,u,v,a,b,x,y,bx,by,nx,ny;
int px[5001],py[5001];
string s;
int main()
{
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
        cin>>s;
        n=s.length();
        for (i=1;i<=n;i++)
        {
            px[i]=px[i-1];
            py[i]=py[i-1];
            if (s[i-1]=='L') px[i]--;
            if (s[i-1]=='R') px[i]++;
            if (s[i-1]=='D') py[i]--;
            if (s[i-1]=='U') py[i]++;
        }
        int done=0;
        for (i=1;i<=n;i++)
        {
            bx=px[i];
            by=py[i];
            x=0;
            y=0;
            for (j=1;j<=n;j++)
            {
                nx=x;
                ny=y;
            if (s[j-1]=='L') nx--;
            if (s[j-1]=='R') nx++;
            if (s[j-1]=='D') ny--;
            if (s[j-1]=='U') ny++;
                if (!((nx==bx)and(ny==by)))
                {
                    x=nx;
                    y=ny;
                }
            }
            if ((x==0)and(y==0)){ cout<<bx<<' '<<by<<endl; done=1; break;}
        }
        if (!done ) cout<<0<<' '<<0<<endl;
    }
}