#include <bits/stdc++.h>

using namespace std;

long long sum(long long a)
{
    return a*(a+1)/2;
}

long long calculate(long long s)
{

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,x;
    cin>>n>>x;
    long long tab[n+7];
    long long pref[n+7];
    long long res[n+7];
    res[0]=0;
    pref[0]=0;
    set <pair<long long,long long> > prefiks;
    prefiks.insert(make_pair(0,0));
    prefiks.insert(make_pair(10e17+7,10e8+7));
    set <pair<long long,long long> >::iterator it;
    pair<long long,long long> par;
    long long itr;
    long long s;
    for(int i=1;i<=n;i++)
    {
        cin>>tab[i];
        pref[i]=pref[i-1]+tab[i];
        res[i]=res[i-1]+tab[i]*(tab[i]+1)/2;
        prefiks.insert(make_pair(pref[i],i));
    }
    long long ans=0;
    long long res1=0,res2=0;
    for(int i=1;i<=n;i++)
    {
        long long l=1, p=tab[i]-1,sr,ans1;
        if(tab[i]==1)
        {
            res1=0,res2=0;
            s=pref[i-1]+1;
            it=prefiks.upper_bound(make_pair(s+x-1,0));
            it--;
            par=*it;
            itr=par.second;

            res1+=sum(min(tab[i],1+x-1))-sum(1-1);
            if(itr>i)
                res1+=res[itr]-res[i];

            if(itr==n)
            {
                long long reszta=x-(pref[itr]-s+1);
                it=prefiks.upper_bound(make_pair(reszta,0));
                it--;
                par=*it;
                itr=par.second;
                res1+=res[itr];
                res1+=sum(reszta-pref[itr]);

            }
            else if(itr>=i) res1+=sum(x-(pref[itr]-s+1));
            ans1=res1;
        }
        while(l<=p)
        {
            res1=0,res2=0;
            sr=(l+p)/2;
            s=pref[i-1]+sr;
            it=prefiks.upper_bound(make_pair(s+x-1,0));
            it--;
            par=*it;
            itr=par.second;

            res1+=sum(min(tab[i],sr+x-1))-sum(sr-1);

            if(itr>i)
                res1+=res[itr]-res[i];
            if(itr==n)
            {
                long long reszta=x-(pref[itr]-s+1);
                it=prefiks.upper_bound(make_pair(reszta,0));
                it--;
                par=*it;
                itr=par.second;
                res1+=res[itr];
                res1+=sum(reszta-pref[itr]);

            }
            else if(itr>=i) res1+=sum(x-(pref[itr]-s+1));


            s=pref[i-1]+sr+1;
            it=prefiks.upper_bound(make_pair(s+x-1,0));
            it--;
            par=*it;
            itr=par.second;

            res2+=sum(min(tab[i],sr+1+x-1))-sum(sr);
            if(itr>i)
                res2+=res[itr]-res[i];
            if(itr==n)
            {
                long long reszta=x-(pref[itr]-s+1);
                it=prefiks.upper_bound(make_pair(reszta,0));
                it--;
                par=*it;
                itr=par.second;
                res2+=res[itr];
                res2+=sum(reszta-pref[itr]);

            }
            else if(itr>=i) res2+=sum(x-(pref[itr]-s+1));
           if(res1>=res2)
           {
                p=sr-1;
                ans1=res1;
           }
           else
           {
                l=sr+1;
                ans1=res2;
           }
        }
        ans=max(ans,ans1);
    }
    cout<<ans<<endl;
    return 0;
}