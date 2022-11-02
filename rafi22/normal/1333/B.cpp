    #include <bits/stdc++.h>
     
    using namespace std;
    int a1[100007];
    int a2[100007];
     
    int main()
    {
        int t,n;
        cin>>t;
        for(int i=0;i<t;i++)
        {
            cin>>n;
            int tab[n+1];
            int tab1[n+1];
     
            for(int j=1;j<=n;j++)
            {
                cin>>tab[j];
            }
            for(int j=1;j<=n;j++) cin>>tab1[j];
            for(int j=1;j<=n;j++)
            {
                a1[j]=a1[j-1];
                a2[j]=a2[j-1];
                if(tab[j]==1) a1[j]++;
                if(tab[j]==-1) a2[j]++;
                //cout<<a1[j]<<" "<<a2[j]<<endl;
            }
            bool ok=1;
            for(int j=1;j<=n;j++)
            {
                if(tab1[j]-tab[j]>0)
                {
                    if(a1[j-1]>0) ;
                    else ok=0;
                }
                else if(tab1[j]-tab[j]<0)
                {
                    if(a2[j-1]>0) ;
                    else ok=0;
                }
            }
            if(ok) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            for(int j=0;j<=n;j++)
            {
                a1[j]=0;
                a2[j]=0;
            }
        }
        return 0;
    }