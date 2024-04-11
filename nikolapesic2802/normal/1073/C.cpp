#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()
int x,y;
ll dist(int a,int b)
{
    return (ll)abs(a-x)+(ll)abs(b-y);
}
int main()
{
    int n;
    scanf("%i",&n);
    string s;
    cin >> s;
    scanf("%i %i",&x,&y);
    if(dist(0,0)%2!=n%2)
    {
        printf("-1\n");
        return 0;
    }
    vector<pair<int,int> > pom(n+1);
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='R')
        {
            pom[i]=make_pair(pom[i+1].first+1,pom[i+1].second);
        }
        if(s[i]=='L')
        {
            pom[i]=make_pair(pom[i+1].first-1,pom[i+1].second);
        }
        if(s[i]=='U')
        {
            pom[i]=make_pair(pom[i+1].first,pom[i+1].second+1);
        }
        if(s[i]=='D')
        {
            pom[i]=make_pair(pom[i+1].first,pom[i+1].second-1);
        }
        //printf("Pom od %i: %i %i\n",i,pom[i].first,pom[i].second);
    }
    int minn=INT_MAX;
    int xx=0,yy=0;
    for(int i=0;i<n;i++)
    {
        int l=i,r=n;
        while(l<r)
        {
            int mid=(l+r)/2;
            //printf("Uzimam %i: %lld, mid:%i, i:%i\n",mid,dist(xx+pom[mid].first,yy+pom[mid].second),mid,i);
            if(dist(xx+pom[mid].first,yy+pom[mid].second)<=mid-i)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        //printf("%i: %i\n",i,l);
        if(dist(xx+pom[l].first,yy+pom[l].second)<=l-i)
        {
            minn=min(minn,l-i);
        }
        if(s[i]=='R')
        {
            xx++;
        }
        if(s[i]=='L')
        {
            xx--;
        }
        if(s[i]=='U')
        {
            yy++;
        }
        if(s[i]=='D')
        {
            yy--;
        }
    }
    if(xx==x&&yy==y)
        minn=0;
    if(minn==INT_MAX)
    {
        printf("-1\n");
        return 0;
    }
    printf("%i\n",minn);
    return 0;
}