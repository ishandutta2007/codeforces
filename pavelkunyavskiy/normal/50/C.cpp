#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define x first
#define y second

using namespace std;

typedef long long int64;
typedef long double ld;

typedef pair<int,int> point;

bool cmp(const point& a,const point& b){
    int64 tmp=a.x*1LL*b.y - a.y*1LL*b.x;
    if (tmp!=0)
        return tmp > 0;
    return a.x*1LL*a.x + a.y*1LL*a.y < a.x*1LL*a.x + a.y*1LL*a.y;
}

bool cmpxy(const point& a,const point& b){
    if (a.y!=b.y)
        return a.y<b.y;
    return a.x<b.x;
}

bool good(const point& a,const point& b,const point& c){
    int x1=b.x-a.x;
    int y1=b.y-a.y;
    int x2=c.x-a.x;
    int y2=c.y-a.y;
    return x1*1LL*y2-x2*1LL*y1 > 0;
}

void convex(vector<point>& a){
    int n=a.size();
    sort(a.begin(),a.end(),cmpxy);
    a.erase(unique(a.begin(),a.end()),a.end());
    n=a.size();
    for (int i=n-1;i>=0;--i){
        a[i].x-=a[0].x;
        a[i].y-=a[0].y;
    }   
    sort(a.begin()+1,a.end(),cmp);  
    vector<point> v;
    v.pb(a[0]);
    v.pb(a[1]);
    for (int i=2;i<n;i++){
        for (;v.size()>2 && !good(v[v.size()-2],v[v.size()-1],a[i]);v.pop_back());
        v.pb(a[i]);
    }
    a=v;
    return;
}

vector<point> v;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        for (int j=0;j<4;j++)
            v.pb(mp(x+dx[j],y+dy[j]));
    }
    convex(v);
    v.pb(v[0]);
    int64 ans=0;
    for (int i=0;i+1<v.size();i++)
        ans+=max(abs(v[i].x-v[i+1].x),abs(v[i].y-v[i+1].y));
    cout<<ans<<endl;
    return 0;
}