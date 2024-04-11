#include <cstdio>
#include <set>

using namespace std;

struct comp {
    bool operator()(const int& a,const int& b){
        return a%10<b%10;
    }
};

multiset<int,comp> s;
int n,k;
int ans=0;

int min(int a,int b){ return a>b?b:a; }

int main()
{
    scanf("%d%d",&n,&k);
    int i, buf;
    for(i=0;i<n;++i){
        scanf("%d",&buf);
        ans+=buf/10;
        if(buf!=100) s.insert(buf);
    }
    int adding;
    while(k && s.size()){
        auto it=s.end(); --it;
        buf=*it;
        s.erase(it);
        if(buf==100) continue;
        adding = min(k,10-buf%10);
        s.insert(buf+adding);
        k-=adding;
        if((buf+adding)/10 > buf/10) ++ans;
    }
    printf("%d\n",ans);
    return 0;
}