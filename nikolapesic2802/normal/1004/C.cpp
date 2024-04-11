#include <bits/stdc++.h>

using namespace std;
int visited1[100010],visited2[100010];
set<pair<int,int> > set1,set2;
int main()
{
    set1.insert(make_pair(0,0));
    set2.insert(make_pair(0,0));
    int n;
    scanf("%i",&n);
    int niz[n];
    for(int i=0;i<n;i++)
    {
        scanf("%i",&niz[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(visited1[niz[i]]==0)
        {
            visited1[niz[i]]=i+1;
            set1.insert(make_pair(i+1,set1.size()));
        }
    }
    int counter=0;
    for(int i=n-1;i>=0;i--)
    {
        if(visited2[niz[i]]==0)
        {
            visited2[niz[i]]=counter+1;
            //printf("dodajem %i %i\n",counter+1,set2.size());
            set2.insert(make_pair(counter+1,set2.size()));
        }
        counter++;
    }
    set1.insert(make_pair(100005,set1.size()));
    set2.insert(make_pair(100005,set2.size()));
    long long broj=0;
    /*for(int i=0;i<100005;i++)
    {
        if(visited2[i]!=0)
        {
            printf("Ako odaberem %i dodjem do %i 22\n",i,visited2[i]);
        }
    }*/
    for(int i=0;i<100005;i++)
    {
        if(visited1[i]!=0)
        {
            //printf("Ako odaberem %i dodjem do %i\n",i,visited1[i]);
            int mesto=n-visited1[i];
            //printf("%i\n",mesto);
            set<pair<int,int> >::iterator it=set2.lower_bound(make_pair(mesto,0));
            pair<int,int> lol=*it;
            //printf("%i %i\n",lol.first,lol.second);
            if(lol.first>mesto)
            {
                it--;
                lol=*it;
            }
            broj+=(long long)lol.second;
        }
    }
    printf("%I64d\n",broj);
    /*for(int i=0;i<100005;i++)
    {
        if(visited2[i]!=0)
        {
            //printf("Ako odaberem %i dodjem do %i\n",i,visited1[i]);
            int mesto=n-visited2[i];
            //printf("%i\n",mesto);
            set<pair<int,int> >::iterator it=set1.lower_bound(make_pair(mesto,0));
            pair<int,int> lol=*it;
            //printf("%i %i\n",lol.first,lol.second);
            if(lol.first>mesto)
            {
                it--;
                lol=*it;
            }
            broj+=lol.second;
        }
    }
    printf("%i\n",broj/2);*/
    return 0;
}