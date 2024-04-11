#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=1e7+5;

int primes[nax];
vector<int> idx[nax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int res=1e18;
    int idx1;
    int idx2;
    memset(primes,0,sizeof primes);
    int n; cin>>n;
    int * a=new int[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        idx[a[i]].push_back(i);
    }
    for(int i=1;i<nax;i++)
    {
        int cnt=0;
        pair<int,int> w1,w2;
        w1.first=-33;
        for(int j=i;j<nax;j+=i)
        {
            if(idx[j].size()>0)
            {
                if(cnt==0)
                {
                    w1.first=j;
                    w1.second=idx[j][0];
                    cnt++;
                }
                else
                {
                    w2.first=j;
                    w2.second=idx[j][0];
                    cnt++;
                }
            }
            if(cnt==2) break;
            if(idx[j].size()>1)
            {
                w2.first=j;
                w2.second=idx[j][1];
                cnt++;
            }
            if(cnt==2) break;
        }
        if(cnt<2) continue;
        long long int wynik=(long long int)w1.first*w2.first;
        wynik/=i;
        if(wynik<res)
        {
            res=wynik;
            idx1=w1.second;
            idx2=w2.second;
        }
    }
    if(idx1>idx2) swap(idx1,idx2);
    cout<<idx1<<" "<<idx2<<endl;
    return 0;
}