    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main()
    {
        long long t,n,k;
        cin>>t;
        for(int i=0;i<t;i++)
        {
            cin>>n>>k;
            long long tab[n];
            for(int j=0;j<n;j++)
            {
                cin>>tab[j];
            }
            sort(tab,tab+n,greater<long long>());
            long long it=0,nadwyzka=0;
            while(it<n&&tab[it]>k)
            {
                nadwyzka+=tab[it]-k;
                it++;
            }
          //  cout<<it<<endl;
            while(it<n&&nadwyzka>=k-tab[it])
            {
                nadwyzka-=k-tab[it];
                it++;
            }
            cout<<it<<endl;
        }
        return 0;
    }