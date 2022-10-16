#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main()
{
    int n,m,cl,ce,v;
    scanf("%i %i %i %i %i",&n,&m,&cl,&ce,&v);
    set<int> lift,stepenice;
    for(int i=0;i<cl;i++)
    {
        int a;
        scanf("%i",&a);
        stepenice.insert(a);
    }
    for(int i=0;i<ce;i++)
    {
        int a;
        scanf("%i",&a);
        lift.insert(a);
    }
    int q;
    scanf("%i",&q);
    while(q-->0)
    {
        int x1,y1,x2,y2;
        scanf("%i %i %i %i",&x1,&y1,&x2,&y2);
        if(y1>y2)
            swap(y1,y2);
        int minn=INT_MAX;
        if(x1==x2)
            minn=abs(y1-y2);
        int liftom=abs(x1-x2)/v;
        if(abs(x1-x2)%v!=0)
            liftom++;
        set<int>::iterator it=stepenice.lower_bound(y1);
        if(it!=stepenice.end())
        {
            int l=*it;
            int res=abs(y1-l)+abs(y2-l)+abs(x1-x2);
            minn=min(minn,res);
        }
        if(it!=stepenice.begin())
        {
            it--;
            int l=*it;
            int res=abs(y1-l)+abs(y2-l)+abs(x1-x2);
            minn=min(minn,res);
        }
        it=lift.lower_bound(y1);
        if(it!=lift.end())
        {
            int l=*it;
            int res=abs(y1-l)+abs(y2-l)+liftom;
            minn=min(minn,res);
        }
        if(it!=lift.begin())
        {
            it--;
            int l=*it;
            int res=abs(y1-l)+abs(y2-l)+liftom;
            minn=min(minn,res);
        }
        printf("%i\n",minn);
    }
    return 0;
}