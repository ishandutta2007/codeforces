    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main()
    {
        long long n,a,b;
        cin>>n;
        long long tab[n];
        long long u[n];
        long long na[n];
        for(int i=0;i<n;i++)
        {
            cin>>na[i];
        }
        for(int i=0;i<n;i++) cin>>u[i];
        for(int i=0;i<n;i++)
        {
            tab[i]=na[i]-u[i];
        }
        sort(tab,tab+n);
        long long it=n;
        long long wyn=0;
        for(long long i=0;i<n-1;i++)
        {
            while(tab[it-1]+tab[i]>0&&it-1>i) it--;
            //cout<<it<<endl;
     
            wyn+=n-max(it,i+1);
     
        }
        cout<<wyn<<endl;
        return 0;
    }