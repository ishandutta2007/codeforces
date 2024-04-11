

    #include <iostream>
     
    using namespace std;
     
    int first[5007];
     
    int main()
    {
        int t,n;
        cin>>t;
        for(int j=0;j<t;j++)
        {
            cin>>n;
            int tab[n];
            for(int i=1;i<=n;i++) cin>>tab[i];
            bool is=0;
            for(int i=1;i<=n;i++)
            {
                if(first[tab[i]]>0)
                {
                    if(first[tab[i]]<i-1) is=1;
                }
                else
                {
                    first[tab[i]]=i;
                }
            }
            for(int i=0;i<=n;i++) first[i]=0;
     
            if(is) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
     
        }
     
        return 0;
    }