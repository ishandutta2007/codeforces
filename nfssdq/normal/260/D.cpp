#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <typeinfo>
#include <locale>
#include <iterator>
#include <valarray>
#include <complex>
using namespace std;

#define xx first
#define yy second
#define LL long long
priority_queue<pair<int,int> >pq[2];
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a;
    for(x=0;x<a;x++)
    {
        scanf("%d %d",&c,&b);
        pq[c].push(make_pair(b,x+1));
    }
    b=0;
    while(!pq[0].empty() && !pq[1].empty())
    {
        if(b>a)break;
        pair<int,int>p,q;
        p=pq[0].top();
        q=pq[1].top();
        pq[0].pop();
        pq[1].pop();
        cout<<p.yy<<" "<<q.yy<<" "<<min(p.xx,q.xx)<<endl;
        if(p.xx<q.xx || (p.xx==q.xx && pq[0].size()>=pq[1].size()))
        {
            q.xx-=p.xx;
            pq[1].push(q);
        }
        else
        {
            p.xx-=q.xx;
            pq[0].push(p);
        }
        b++;
    }
}