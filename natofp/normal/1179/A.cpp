#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=1e5+5;
int a[nax];
int n,q;
pair<int,int> res[nax*3];
pair<int,int> wynik[nax*3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<pair<long long int,int> > qq;
    for(int i=0;i<q;i++)
    {
        long long int m; cin>>m;
        qq.push_back({m,i+1});
    }
    sort(qq.begin(),qq.end());
    int idx=-1;
    int naj=-1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>naj)
        {
            naj=a[i];
            idx=i;
        }
    }
    int wsk1=1;
    int wsk2=2;
    vector<int> koniec;
    for(int i=idx+1;i<=n;i++)
    {
        koniec.push_back(a[i]);
    }
    int ile=1;
    while(a[wsk1]!=naj)
    {
        if(wsk1>wsk2) swap(wsk1,wsk2);
        //cout<<wsk1<<" "<<a[wsk1]<<endl;
        if(a[wsk1]==naj) break;
        wynik[ile].first=a[wsk1];
        wynik[ile].second=a[wsk2];
        ile++;
        if(a[wsk1]>a[wsk2])
        {
            koniec.push_back(a[wsk2]);
            wsk2++;
        }
        else
        {
            koniec.push_back(a[wsk1]);
            wsk1=wsk2+1;
        }
        if(wsk1>wsk2) swap(wsk1,wsk2);
    }
    for(int i=0;i<q;i++)
    {
        long long int zap=qq[i].first;
        int kappa=qq[i].second;
        if(zap<idx)
        {
            res[kappa].first=wynik[zap].first;
            res[kappa].second=wynik[zap].second;
        }
        else if(zap>=idx)
        {
            res[kappa].first=naj;
            zap-=idx;
            res[kappa].second=koniec[zap%(n-1)];
        }
    }
    for(int i=1;i<=q;i++)
    {
        cout<<res[i].first<<" "<<res[i].second<<"\n";
    }
    return 0;
}