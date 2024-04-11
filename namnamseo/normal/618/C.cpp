#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int,int> pp;
int n;
typedef long long ll;
struct v3{
    ll a,b,c;
    v3(){ a=b=c=0; }
    v3(ll x,ll y,ll z){ a=x; b=y; c=z; }
    v3 operator*(v3 x){
        return v3(b*x.c-c*x.b,c*x.a-a*x.c,a*x.b-b*x.a);
    }
};
pair<pp,int> d[100010];
v3 cross(int a,int b){
    return v3(d[a].first.first,d[a].first.second,1)*v3(d[b].first.first,d[b].first.second,1);
}
int main()
{
    scanf("%d",&n);
    int a,b;
    for(int i=1;i<=n;++i) scanf("%d%d",&a,&b), d[i]={{a,b},i};
    sort(d+1,d+n+1);
    int i;
    v3 l1=cross(1,2);
    for(i=3;i<=n;++i){
        v3 l2=cross(2,i);
        if(!(l1.a*l2.c == l2.a*l1.c && l1.a*l2.b == l2.a*l1.b)) break;
    }
    printf("%d %d %d\n",d[1].second,d[2].second,d[i].second);
    return 0;
}