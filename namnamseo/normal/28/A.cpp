#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
void read(int& a){ scanf("%d",&a); }
void read(long long& a){ scanf("%I64d",&a); }
void read(double& a){ scanf("%lf",&a); }
template<typename T,typename... Args> void read(T& a,Args&... b){ read(a); read(b...); }
typedef pair<int,int> pp;
vector<pp> data;
int n,m;
multiset<pp> ms;
int stick[501];
int abs(int x){ return x>0?x:-x; }
inline int manhatt(pp a,pp b){ return abs(a.first-b.first)+abs(a.second-b.second); }
inline int dst(pp a,pp b,pp c){ return manhatt(a,b)+manhatt(b,c); }
int ans[501];
int removeStick(int x){
    auto it=ms.lower_bound({x,0});
    if(it == ms.end() || it->first != x) return -1;
    int ret=it->second;
    ms.erase(it);
    return ret;
}
bool calc(int S){
    ms.clear();
    for(int i=1; i<=m; ++i) ms.insert({stick[i],i});
    int ret=dst(data[S], data[S%n+1], data[(S+1)%n+1]);
    
    int tmp=removeStick(ret);
    if(tmp == -1) return false;
    ans[S]=-1;
    ans[S%n+1]=tmp;
    
    int i;
    for(i=(S+1)%n+1; i!=S; i=(i+1)%n+1){
        int cv = dst(data[i], data[i%n+1], data[(i+1)%n+1]);
        int tmp = removeStick(cv);
        if(tmp == -1) return false;
        ans[i%n+1]=tmp;
        ans[i]=-1;
    }
    return true;
}
int main()
{
    read(n,m);
    int i;
    data.push_back({1,2});
    for(i=1; i<=n; ++i){ int a,b; read(a,b); data.push_back({a,b}); }
    for(i=1; i<=m; ++i) read(stick[i]);
    if(calc(1)){
        puts("YES"); for(i=1; i<=n; ++i) printf("%d ",ans[i]);
    } else if(calc(2)){
        puts("YES"); for(i=1; i<=n; ++i) printf("%d ",ans[i]);
    } else puts("NO");
    return 0;
}