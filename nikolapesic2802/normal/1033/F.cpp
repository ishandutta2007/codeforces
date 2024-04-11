#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
vector<int> d(1e6);
int w;
int value[2][2][300];
vector<char> s[50001];
void build(int broj,int poz,int n,int tr)
{
    if(poz==w)
    {
        assert(tr<d.size());
        d[tr]+=n;
        //if(n>0)
        //printf("Dodajem %i, %i\n",tr,n);
        return;
    }
    if(broj&(1<<poz))
    {
        build(broj,poz+1,n,tr*3+1);
        build(broj,poz+1,n,tr*3+2);
    }
    else
    {
        build(broj,poz+1,n,tr*3);
        build(broj,poz+1,n,tr*3+2);
    }
}
/*
    value['A'][0][0]=1;
    value['A'][0][1]=1;


    value['X'][0][0]=0;
    value['X'][0][1]=1;
    value['X'][1][0]=1;
    value['X'][1][1]=0;


    value['O'][0][0]=0;
    value['O'][0][1]=1;
    value['O'][1][0]=1;
    value['O'][1][1]=2;


    value['a'][0][0]=0;
    value['a'][0][1]=2;
    value['a'][1][0]=1;
    value['a'][1][1]=0;


    value['x'][0][0]=0;
    value['x'][0][1]=0;
    value['x'][1][0]=1;
    value['x'][1][1]=1;


    value['o'][0][0]=0;
    value['o'][0][1]=0;
*/
ll b2(int broj,int poz,int tr1,int tr2)
{
    ll res=0;
    if(poz==w)
    {
        ///printf("Uzimam za %i i %i\n",tr1,tr2);
        return (ll)d[tr1]*d[tr2];
    }
    if(s[broj][w-1-poz]=='a')
    {
        res+=b2(broj,poz+1,tr1*3+1,tr2*3+1);
    }
    if(s[broj][w-1-poz]=='x')
    {
        //printf("X na poz %i\n",poz);
        res+=b2(broj,poz+1,tr1*3+0,tr2*3+1);
        res+=b2(broj,poz+1,tr1*3+1,tr2*3+0);
    }
    if(s[broj][w-1-poz]=='o')
    {
        res+=b2(broj,poz+1,tr1*3+0,tr2*3+1);
        res+=b2(broj,poz+1,tr1*3+1,tr2*3+2);
    }
    if(s[broj][w-1-poz]=='A')
    {
        res+=b2(broj,poz+1,tr1*3+0,tr2*3+2);
        res+=b2(broj,poz+1,tr1*3+1,tr2*3+0);
    }
    if(s[broj][w-1-poz]=='X')
    {
        res+=b2(broj,poz+1,tr1*3+0,tr2*3+0);
        res+=b2(broj,poz+1,tr1*3+1,tr2*3+1);
    }
    if(s[broj][w-1-poz]=='O')
    {
        res+=b2(broj,poz+1,tr1*3+0,tr2*3+0);
    }
    return res;
}
int main()
{
    int n,m;
    scanf("%i %i %i",&w,&n,&m);
    int maxx=1<<w;
    //printf("%i\n",maxx);
    vector<int> c(maxx);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        c[a]++;
    }
    for(int i=0;i<maxx;i++)
    {
        //if(c[i]>0)
        build(i,0,c[i],0);
    }
    char cc[w+1];
    for(int i=0;i<m;i++)
    {
        scanf("%s",cc);
        for(int j=0;j<w;j++)
            s[i].pb(cc[j]);
    }
    for(int i=0;i<m;i++)
    {
        ll broj1=b2(i,0,0,0);
        printf("%lld\n",broj1);
    }
    return 0;
}