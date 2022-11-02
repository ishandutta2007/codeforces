    #include <bits/stdc++.h>
     
    using namespace std;
     
    int DP[2007][2007];
    int tab[2007];
     
    int main()
    {
        int n,h,l,r,t,time=0,wyn=0;
        cin>>n>>h>>l>>r;
        for(int i=1;i<=n;i++) cin>>tab[i];
        for(int i=1;i<=n;i++)
        {
            time+=tab[i];
            time%=h;
            t=time;
           // cout<<time<<endl;
            for(int j=0;j<i+1;j++)
            {
                DP[i][j]=max(DP[i-1][j],DP[i-1][j-1]);
                if(t>=l&&t<=r) DP[i][j]++;
                t--;
                if(t<0) t+=h;
                wyn=max(wyn,DP[i][j]);
            }
        }
        cout<<wyn<<endl;
        return 0;
    }