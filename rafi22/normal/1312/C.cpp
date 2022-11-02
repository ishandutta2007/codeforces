    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main()
    {
        long long t;
        cin>>t;
        long long n,k;
        set <long long> liczby;
        for(long long i=0;i<t;i++)
        {
            cin>>n>>k;
            long long tab[n];
            for(long long j=0;j<n;j++)
            {
                cin>>tab[j];
            }
            bool ok=1;
            long long l=0;
            liczby.clear();
            while(true)
            {
                bool take=0;
                for(long long j=0;j<n;j++)
                {
                   // if(tab[j]!=-1)
                    {
                        if(tab[j]%k>1)
                            ok=0;
                        else if(tab[j]%k==1)
                        {
                            if(take)
                                ok=0;
                            else
                                take=1;
                        }
                        if(tab[j]==0)
                        {
                            liczby.insert(j);
                        }
                        else
                        {
                            tab[j]/=k;
                        }
                    }
     
                }
                if(liczby.size()>=n) break;
            }
            if(ok) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        return 0;
    }