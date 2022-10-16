#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()
int last=0;
const int N=4*1e5+5;
struct Node{
    int rank;
    int data;
    int parent;
    int dist;
};
Node DisjointSet[N];
void makeSet(int x)
{
    DisjointSet[x].rank=0;
    DisjointSet[x].data=x;
    DisjointSet[x].parent=x;
    DisjointSet[x].dist=0;
}
pair<int,int> findSet(int x)
{
    if(DisjointSet[x].parent==x)
        return make_pair(x,0);
    return make_pair(DisjointSet[x].parent=findSet(DisjointSet[x].parent).first,DisjointSet[x].dist=DisjointSet[x].dist^findSet(DisjointSet[x].parent).second);
}
void unija(int x,int y,int d)
{
    int t1=findSet(x).first;
    int t2=findSet(y).first;
    //printf("Set of %i: %i, set od %i: %i\n",x,t1,y,t2);
    if(DisjointSet[t1].rank>DisjointSet[t2].rank)
    {
        DisjointSet[t2].parent=t1;
        DisjointSet[t2].dist=DisjointSet[x].dist^DisjointSet[y].dist^d;
    }
    if(DisjointSet[t1].rank<DisjointSet[t2].rank)
    {
        DisjointSet[t1].parent=t2;
        DisjointSet[t1].dist=DisjointSet[x].dist^DisjointSet[y].dist^d;
    }
    if(DisjointSet[t1].rank==DisjointSet[t2].rank)
    {
        DisjointSet[t2].parent=t1;
        DisjointSet[t2].dist=DisjointSet[x].dist^DisjointSet[y].dist^d;
        DisjointSet[t1].rank++;
    }
}
int t=1;
map<int,int> mapa;
int main()
{
    int n;
    scanf("%i",&n);
    for(int i=0;i<n;i++)
    {
        int te;
        scanf("%i",&te);
        if(te==1)
        {
            int l,r,x;
            scanf("%i %i %i",&l,&r,&x);
            l^=last;
            r^=last;
            x^=last;
            if(l>r)
                swap(l,r);
            r++;
            //printf("%i %i %i\n",l,r,x);
            if(mapa[l]==0)
            {
                mapa[l]=t;
                makeSet(t);
                t++;
            }
            l=mapa[l];
            if(mapa[r]==0)
            {
                mapa[r]=t;
                makeSet(t);
                t++;
            }
            r=mapa[r];
            int v1=findSet(l).first;
            int v2=findSet(r).first;
            if(v1!=v2)
            {
                unija(l,r,x);
            }
        }
        else
        {
            int l,r;
            scanf("%i %i",&l,&r);
            l^=last;
            r^=last;
            if(l>r)
                swap(l,r);
            r++;
            //printf("%i %i\n",l,r);
            if(mapa[l]==0)
            {
                mapa[l]=t;
                makeSet(t);
                t++;
            }
            l=mapa[l];
            if(mapa[r]==0)
            {
                mapa[l]=t;
                makeSet(t);
                t++;
            }
            r=mapa[r];
            int v1=findSet(l).first;
            int v2=findSet(r).first;
            if(v1!=v2)
            {
                printf("-1\n");
                last=1;
            }
            else
            {
                int res=findSet(l).second^findSet(r).second;
                printf("%i\n",res);
                last=res;
            }
        }
    }
    return 0;
}