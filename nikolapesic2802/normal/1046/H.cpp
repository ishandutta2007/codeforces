#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
int convert(int niz[27])
{
    int res=0;
    for(int i=0;i<27;i++)
    {
        if(niz[i])
        {
            res+=1<<i;
        }
    }
    return res;
}
int main()
{
    int n;
    scanf("%i",&n);
    map<int,int> mapa;
    vector<int> l;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        int broj[27]={};
        for(int i=0;i<s.size();i++)
        {
            int b=s[i]-'a';
            broj[b]=(broj[b]+1)%2;
        }
        l.pb(convert(broj));
        //printf("Dodajem %i\n",convert(broj));
        mapa[convert(broj)]++;
    }
    ll resenje=0;
    for(int i=0;i<n;i++)
    {
        //printf("Gledam za %i:\nisti: %i\n",l[i],mapa[l[i]]-1);
        resenje+=mapa[l[i]]-1;
        for(int j=0;j<27;j++)
        {
            int tr=l[i];
            //printf("1 shifrovano za %i:%i  %i  %i\n",i,1<<i,tr,tr^(1<<i));
            tr=tr^(1<<j);
            resenje+=mapa[tr];
            //printf("Gledam za %i: %i\n",tr,mapa[tr]);
        }
    }
    printf("%lld\n",resenje/2);
    return 0;
}