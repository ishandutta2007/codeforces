#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    multiset<int> sx_min,sx_max,sy_min,sy_max;
    int x_min[n],x_max[n],y_min[n],y_max[n];
    for(int i=0;i<n;i++)
    {
        int a,b,c,d;
        scanf("%i %i %i %i",&a,&b,&c,&d);
        x_min[i]=min(a,c);
        x_max[i]=max(a,c);
        y_min[i]=min(b,d);
        y_max[i]=max(b,d);
        sx_min.insert(x_min[i]);
        sy_min.insert(y_min[i]);
        sx_max.insert(x_max[i]);
        sy_max.insert(y_max[i]);
    }
    for(int i=0;i<n;i++)
    {
        sx_min.erase(sx_min.find(x_min[i]));
        sy_min.erase(sy_min.find(y_min[i]));
        sy_max.erase(sy_max.find(y_max[i]));
        sx_max.erase(sx_max.find(x_max[i]));
        multiset<int>::iterator it=sx_min.end();
        it--;
        int x=*it;
        it=sx_max.begin();
        if(x<=*it)
        {
            it=sy_min.end();
            it--;
            int y=*it;
            it=sy_max.begin();
            if(y<=*it)
            {
                printf("%i %i",x,y);
                return 0;
            }
        }
        sx_min.insert(x_min[i]);
        sy_min.insert(y_min[i]);
        sx_max.insert(x_max[i]);
        sy_max.insert(y_max[i]);
    }
    return 0;
}