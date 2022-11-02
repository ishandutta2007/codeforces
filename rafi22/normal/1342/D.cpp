#include <bits/stdc++.h>

using namespace std;

vector <int> testy[200007];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*int a=0;
    for(int i=1000;i<=9995;i++)
    {
        if(i%4%6==i%6%4) a++;
    }
    cout<<a<<endl;*/
    int n,k;
    cin>>n>>k;
    int tab[n+7];
    int limit[k+7];
    for(int i=0;i<n;i++) cin>>tab[i];
    sort(tab,tab+n);
    for(int i=1;i<=k;i++) cin>>limit[i];
    int tests=0;
    int it=0,last=0;

    for(int i=1;i<=k;i++)
    {
        while(it<n&&tab[it]<i) it++;
       // cout<<(int)ceil((double)(n-it)/(double)limit[i])<<endl;
        tests=max(tests,(int)ceil((double)(n-it)/(double)limit[i]));
    }
    for(int i=0;i<n;i++)
    {
        testy[i%tests].push_back(tab[i]);
    }
    cout<<tests<<endl;
    for(int i=0;i<tests;i++)
    {
        cout<<testy[i].size()<<" ";
        for(int j=0;j<testy[i].size();j++)
        {
            cout<<testy[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}