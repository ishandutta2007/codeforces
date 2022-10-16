#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()
const int N=3*1e5+5;
int area(vector<pair<int,int> > points)
{
    int maxx,minx,maxy,miny;
    sort(points.begin(),points.end());
    maxx=points[0].first;
    minx=points[points.size()-1].first;
    for(int i=0;i<points.size();i++)
        swap(points[i].first,points[i].second);
    sort(points.begin(),points.end());
    maxy=points[0].first;
    miny=points[points.size()-1].first;
    return -1*(maxx-minx+maxy-miny);
}
int main()
{
    int n;
    scanf("%i",&n);
    vector<pair<int,int> > points(n);
    for(int i=0;i<n;i++)
    {
        scanf("%i %i",&points[i].first,&points[i].second);
    }
    int maxx,minx,maxy,miny;
    sort(points.begin(),points.end());
    vector<pair<int,int> > consider;
    consider.pb(points[0]);
    consider.pb(points[n-1]);
    maxx=points[0].first;
    minx=points[n-1].first;
    //printf("%i %i\n",maxx,minx);
    for(int i=0;i<n;i++)
        swap(points[i].first,points[i].second);
    sort(points.begin(),points.end());
    consider.pb({points[0].second,points[0].first});
    consider.pb({points[n-1].second,points[n-1].first});;
    maxy=points[0].first;
    miny=points[n-1].first;
    for(int i=0;i<n;i++)
        swap(points[i].first,points[i].second);
    sort(consider.begin(),consider.end());
    consider.erase(unique(consider.begin(),consider.end()),consider.end());
    int ma=0;
    for(int j=0;j<consider.size();j++)
    {
        for(int l=0;l<consider.size();l++)
        {
            for(int i=0;i<n;i++)
            {
                vector<pair<int,int> > lol;
                lol.pb(consider[j]);
                lol.pb(consider[l]);
                lol.pb(points[i]);
                ma=max(ma,area(lol));
            }
        }
    }
    printf("%i ",2*ma);
    for(int i=n;i>=4;i--)
    {
        printf("%i ",-2*(maxx-minx+maxy-miny));
    }
    return 0;
}