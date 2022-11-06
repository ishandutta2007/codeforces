#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pp;
void read(int& a){ scanf("%d",&a); }
template<typename T,typename... Args> void read(T& a,Args&... b){ read(a); read(b...); }
int n;
int x[200010];
int y[200010];
vector<int> xs,ys;
int xc[200010];
int yc[200010];
map<pp,int> m;
int main()
{
    read(n);
    int i;
    for(i=0;i<n;++i){
        read(x[i],y[i]);
        xs.push_back(x[i]);
        ys.push_back(y[i]);
    }
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    sort(ys.begin(),ys.end());
    ys.erase(unique(ys.begin(),ys.end()),ys.end());
    for(i=0;i<n;++i){
        ++xc[lower_bound(xs.begin(),xs.end(),x[i])-xs.begin()];
        ++yc[lower_bound(ys.begin(),ys.end(),y[i])-ys.begin()];
    }
    typedef long long ll;
    ll ans=0;
    for(i=0;i<n;++i){
        ans+=xc[i]*(xc[i]-1ll)/2;
        ans+=yc[i]*(yc[i]-1ll)/2;
        int& tmp=m[{x[i],y[i]}];
        ans-=tmp; ++tmp;
    }
    printf("%I64d\n",ans);
    return 0;
}