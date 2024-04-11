#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    set<pair<int,int> > intervali;
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        //a--;
        //b--;
        //intervali.insert(make_pair(a,b));
    }
    int tr=0;
    for(int i=0;i<n;i++)
    {
        printf("%i",tr);
        tr=(tr+1)%2;
    }
    return 0;
}