#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%i %i",&n,&k);
    int p[n],c[n];
    vector<pair<int,pair<int,int> > > kings;
    long long resenja[n];
    for(int i=0;i<n;i++)
    {

        scanf("%i",&p[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%i",&c[i]);
        resenja[i]=c[i];
    }
    for(int i=0;i<n;i++)
    {
        kings.push_back(make_pair(p[i],make_pair(c[i],i)));
    }
    sort(kings.rbegin(),kings.rend());
    set<pair<int,int> > s;
    for(int i=0;i<n;i++)
    {
        s.insert(make_pair(c[i],i));
    }
    for(int i=0;i<n;i++)
    {
        s.erase(kings[i].second);
        set<pair<int,int> >::iterator it=s.end();
        int siz=s.size();
        //printf("%i  size:%i  %i %i\n",i,siz,kings[i].second.first,kings[i].second.second);
        for(int f=0;f<min(k,siz);f++)
        {
            it--;
            //printf("%i %i\n",(*it).first,(*it).second);
            resenja[kings[i].second.second]+=(long long)(*it).first;
            //printf("%i\n",resenja[kings[i].second.second]);
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%I64d ",resenja[i]);
    }
    return 0;
}