#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
set<pair<int,int> > s1,s2,p2;
int delta1=0,delta2=0;
void ispisi()
{
    set<pair<int,int> >::iterator it;
    printf("S1 delta: %i, sadrzi:\n",delta1);
    for(it=s1.begin();it!=s1.end();it++)
    {
        printf("%i %i\n",(*it).first,(*it).second);
    }
    printf("S2 delta: %i, sadrzi:\n",delta2);
    for(it=s2.begin();it!=s2.end();it++)
    {
        printf("%i %i\n",(*it).first,(*it).second);
    }
    printf("P2 sadrzi:\n");
    for(it=p2.begin();it!=p2.end();it++)
    {
        printf("%i %i\n",(*it).first,(*it).second);
    }
}
int main()
{
    int n;
    scanf("%i",&n);
    vector<int> poz(n+1);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        poz[a]=i;
        //printf("Poz od %i: %i\n",a,poz[a]);
    }
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        //printf("Poz od %i: %i\n",a,poz[a]);
        if(i>=poz[a])
        {
            s1.insert({i-poz[a],a});
        }
        else
        {
            s2.insert({poz[a]-i,a});
            p2.insert({i,a});
        }
    }
    //ispisi();
    printf("%i\n",min((*s1.begin()).first-delta1,(*s2.begin()).first+delta2));
    for(int i=1;i<n;i++)
    {
        delta1--;
        delta2++;
        while(s1.size()>0&&(*s1.begin()).first+delta1<0)
        {
            int a=(*s1.begin()).second;
            //printf("Usao za %i\n",a);
            //ispisi();
            s2.insert({1-delta2,a});
            p2.insert({poz[a]-1-delta1,a});
            s1.erase(s1.begin());
            //printf("Na kraju:\n");
            //ispisi();
        }
        while(p2.size()>0&&(*p2.begin()).first+delta1<0)
        {
            int a=(*p2.begin()).second;
            //printf("Usao2 za %i\n",a);
            //ispisi();
            s2.erase(s2.find({-(*p2.begin()).first+poz[a],a}));
            s1.insert({n-1-poz[a]-delta1,a});
            p2.erase(p2.begin());
            //printf("Na kraju:\n");
            //ispisi();
        }
        printf("%i\n",min((*s1.begin()).first+delta1,(*s2.begin()).first+delta2));
    }
    return 0;
}