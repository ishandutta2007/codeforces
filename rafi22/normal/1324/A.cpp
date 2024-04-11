    #include <iostream>
     
    using namespace std;
     
    int main()
    {
        int t,n;
        cin>>t;
        for(int i=0;i<t;i++)
        {
            cin>>n;
            int tab[n];
            for(int j=0;j<n;j++) cin>>tab[j];
            bool paz;
            if(tab[0]%2==0) paz=0;
            else paz=1;
            bool ok=1;
            for(int j=1;j<n;j++)
            {
                if(paz)
                {
                    if(tab[j]%2==0) ok=0;
                }
                else
                {
                    if(tab[j]%2==1) ok=0;
                }
            }
            if(ok) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
     
        }
        return 0;
    }