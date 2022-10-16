#include <bits/stdc++.h>

using namespace std;
const int maxx=2147483647;
set<int> brojevi;
set<pair<int,pair<pair<int,int>,pair<int,int> > > > brojevi2;
int main()
{
    int x;
    scanf("%i",&x);
    int res[12];
    for(int n=1;n<12;n++)
    {
        brojevi2.clear();
        brojevi.clear();
    brojevi2.insert(make_pair(n,make_pair(make_pair(n,0),make_pair(0,0))));
    set<pair<int,pair<pair<int,int>,pair<int,int> > > >::iterator it=brojevi2.begin();
    while((*it).first<maxx&&brojevi2.size()>0)
    {
        pair<int,pair<pair<int,int>,pair<int,int> > > i=*it;
        //printf("%i  %i %i %i %i\n",i.first,i.second.first.first,i.second.first.second,i.second.second.first,i.second.second.second);
        brojevi.insert(i.first);
        if(i.second.first.first>0)
        {
            //printf("1\n");
            brojevi2.insert(make_pair(i.first+4,make_pair(make_pair(i.second.first.first-1,i.second.first.second+1),make_pair(i.second.second.first,i.second.second.second))));
            brojevi2.insert(make_pair(i.first+9,make_pair(make_pair(i.second.first.first-1,i.second.first.second),make_pair(i.second.second.first+1,i.second.second.second))));
            brojevi2.insert(make_pair(i.first+49,make_pair(make_pair(i.second.first.first-1,i.second.first.second),make_pair(i.second.second.first,i.second.second.second+1))));
        }
        if(i.second.first.second>0)
        {
            //printf("2\n");
            brojevi2.insert(make_pair(i.first+5,make_pair(make_pair(i.second.first.first,i.second.first.second-1),make_pair(i.second.second.first+1,i.second.second.second))));
            brojevi2.insert(make_pair(i.first+45,make_pair(make_pair(i.second.first.first,i.second.first.second-1),make_pair(i.second.second.first,i.second.second.second+1))));
        }
        if(i.second.second.first>0)
        {
            //printf("3\n");
            brojevi2.insert(make_pair(i.first+40,make_pair(make_pair(i.second.first.first,i.second.first.second),make_pair(i.second.second.first-1,i.second.second.second+1))));
        }
        brojevi2.erase(it);
        it=brojevi2.begin();
    }
    res[n]=brojevi.size();
    }
    printf("%lld\n",(long long)49*(max(0,x-11))+res[min(x,11)]);
    //printf("%i\n",res[x]);
    return 0;
}