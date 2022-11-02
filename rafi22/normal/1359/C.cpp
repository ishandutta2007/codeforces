#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin>>x;
    for(int j=0;j<x;j++)
    {
        double h,c,t;
        cin>>h>>c>>t;
        int l=0,p=1000000000,sr,ile;
        double ans1;
        while(l<=p)
        {
            sr=(l+p)/2;
            double res1=((double)sr*(h+c)+h)/(2*(double)sr+1);
            double res2=(((double)sr+1)*(h+c)+h)/(2*(double)sr+3);
            //cout<<sr<<res1<<" "<<res2<<endl;
            if(abs(t-res1)<=abs(t-res2))
            {
                ile=sr;
                ans1=abs(t-res1);
                p=sr-1;
            }
            else
            {
                ile=sr+1;
                ans1=abs(t-res1);
                l=sr+1;
            }
        }
        int L=1,P=1000000000,SR,ILE;
        double ans2;
        while(L<=P)
        {
            SR=(L+P)/2;
            double res1=((double)SR*(h+c))/(2*(double)SR);
            double res2=(((double)SR+1)*(h+c))/(2*(double)SR+2);
            if(abs(t-res1)<=abs(t-res2))
            {
                ILE=SR;
                ans2=abs(t-res1);
                P=SR-1;
            }
            else
            {
                ILE=SR+1;
                ans2=abs(t-res2);
                L=SR+1;
            }
        }
       if(ans1<=ans2)
       {
            cout<<2*ile+1<<endl;
       }
       else
       {
            cout<<2*ILE<<endl;
       }
    }



    return 0;
}