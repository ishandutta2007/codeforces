    #include <bits/stdc++.h>
     
    using namespace std;
     
    long long tab[200007];
    bool is[200007];
    long long index[200007];
     
    int main()
    {
        long long n,k,sum=0,res=1;
        cin>>n>>k;
        long long sorted[n];
        for(int i=0;i<n;i++)
        {
            cin>>tab[i];
            index[tab[i]]=i;
            sorted[i]=tab[i];
        }
        sort(sorted,sorted+n,greater<long long>());
        for(int i=0;i<k;i++)
        {
            sum+=sorted[i];
            is[index[sorted[i]]]=1;
        }
        vector <long long> a;
        for(int i=0;i<n;i++)
        {
            if(is[i]) a.push_back(i);
        }
        for(int i=1;i<a.size();i++)
        {
            res=(res*(a[i]-a[i-1]))%998244353;
            res%=998244353;
        }
        cout<<sum<<" "<<res;
     
     
     
        return 0;
    }