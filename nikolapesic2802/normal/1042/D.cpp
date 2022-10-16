#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
map<int,int> Fen;
map<ll,int> poz;
int MAX=400005;
void upd(int x){
    for(int i=x;i<MAX;i+=(i&(-i)))
    {
        //printf("id: %i\n",i);
        Fen[i]++;
    }
        //Fen[i]++;
}
int Get(int z)
{
    int r=0;
    for(int i=z;i>=1;i-=(i&(-i)))
        r+=Fen[i];
    return r;
}
int main()
{
    int n;
    ll t;
    vector<ll> id;
    scanf("%i %lld",&n,&t);
    ll sum[n];
    scanf("%lld",&sum[0]);
    id.pb(sum[0]);
    id.pb(sum[0]-t+1);
    ll res=0;
    for(int i=1;i<n;i++)
    {
        int d;
        scanf("%i",&d);
        sum[i]=sum[i-1]+(ll)d;
        id.pb(sum[i]);
        id.pb(sum[i]-t+1);
    }
    //id.pb(-200000000000010);
    //id.pb(200000000000010);
    id.pb(0);
    sort(id.begin(),id.end());
    id.erase(unique(id.begin(),id.end()),id.end());
    reverse(id.begin(),id.end());
    MAX=id.size()+1;
    for(int i=0;i<id.size();i++)
    {
        //printf("%lld\n",id[i]);
        poz[id[i]]=i+1;
    }
    //printf("Poz: %i\n",poz[0]);
    upd(poz[0]);
    //printf("Stigao!\n");
    for(int i=0;i<n;i++)
    {
        int tr=Get(poz[sum[i]-t+1]);
        res=res+(ll)tr;
        //printf("Pozicija:%lld : %i, %lld- %i  od %i do 0\n",sum[i],poz[sum[i]],res,tr,poz[sum[i]-t+1]);
        upd(poz[sum[i]]);
    }
    printf("%lld\n",res);
    return 0;
}