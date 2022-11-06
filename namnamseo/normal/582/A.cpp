#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int p[10000];
int pn;

multiset<int> s;

int n;

int ans[510];

int gcd(int a,int b){ return b?gcd(b,a%b):a; }

int main()
{
    int i;
    scanf("%d",&n);
    int buf;
    int nsq=n*n;
    for(i=0;i<nsq;++i) scanf("%d",&buf), s.insert(buf);
    int ind=0;
    while(s.size())
    {
        auto it=s.end(); --it; buf=*it;
        s.erase(it);
        for(i=0;i<ind;++i){
            s.erase(s.find(gcd(ans[i],buf)));
            s.erase(s.find(gcd(ans[i],buf)));
        }
        ans[ind++]=buf;
    }
    for(i=0;i<ind;++i) printf("%d ",ans[i]);
    return 0;
}