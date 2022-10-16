#include <iostream>
#include <bits/stdc++.h>


using namespace std;


int main()
{
    int n,m; cin>>n>>m;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    vector<long long int> res1;
    vector<long long int> res2;
    for(int i=0;i<n/2;i++) res1.push_back(a[i]);
    for(int i=n/2;i<n;i++) res2.push_back(a[i]);
    vector<long long int> sumy1;
    vector<long long int> sumy2;
    int roz1,roz2;
    roz1=n/2;
    roz2=n-n/2;
    for(int i=0;i<(1<<roz1);i++)
    {
        long long int akt=0;
        for(int j=0;j<roz1;j++)
        {
            if(i&(1<<j)) akt+=res1[j];
        }
        akt%=m;
        sumy1.push_back(akt);
    }
    for(int i=0;i<(1<<roz2);i++)
    {
        long long int akt=0;
        for(int j=0;j<roz2;j++)
        {
            if(i&(1<<j)) akt+=res2[j];
        }
        akt%=m;
        sumy2.push_back(akt);
    }
    sort(sumy1.begin(),sumy1.end());
    sort(sumy2.begin(),sumy2.end());
    long long int ans=0;
    ans=sumy1[sumy1.size()-1]+sumy2[sumy2.size()-1];
    ans%=m;
    roz1=(1<<roz1);
    roz2=(1<<roz2);
    int wsk1=0;
    int wsk2=roz2-1;
    for(int i=0;i<roz1;i++)
    {
        while(wsk2>=0 && sumy1[wsk1]+sumy2[wsk2]>=m) wsk2--;
        if(wsk2==-1) break;
        ans=max(ans,sumy1[wsk1]+sumy2[wsk2]);
        wsk1++;
    }
    cout<<ans;
    return 0;
}