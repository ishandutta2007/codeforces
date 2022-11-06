#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
struct bb {
    int v,c,l,r;
} bus[100010];
void read(int& a){ scanf("%d",&a); }
template<typename T,typename... Args> void read(T& a,Args&... b){ read(a); read(b...); }

map<int,vector<int> > m;

int n;
int  dp    [300010];
int  ts    [300010];
int rev    [300010];
int lastuse[300010];
int nt;

int ans[100010], an;

int work(vector<int>& v){
    sort(v.begin(), v.end());
    ts[0]=++nt;
    dp[0]=0;
    
    for(auto& x:v){
        int p=bus[x].l, q=bus[x].l + bus[x].c;
        if(ts[p]==nt){
            if((ts[q]!=nt) || (dp[q]<dp[p]+bus[x].v)){
                dp[q]=dp[p]+bus[x].v;
                ts[q]=nt;
                rev[x]=lastuse[p];
                lastuse[q]=x;
            }
        }
    }
    
    auto& asdf=bus[v[0]];
    int allsum = asdf.c+asdf.l+asdf.r;
    
    if(ts[allsum] == nt) return dp[allsum];
    else return -1;
}

int main()
{
    read(n);
    int i;
    for(i=1; i<=n; ++i){
        int v,c,l,r;
        read(v,c,l,r);
        bus[i]={v,c,l,r};
        m[l+r+c].push_back(i);
    }
    int ai=-1;
    int av=-1;
    for(auto it:m){
        auto& v=it.second;
        int ret = work(v);
        if(ret > av){
            av=ret;
            ai=it.first;
        }
    }
    if(ai == -1){
        puts("0");
        return 0;
    }
    work(m[ai]);
    
    auto& first_elem = bus[m[ai][0]];
    i = lastuse[first_elem.c + first_elem.l + first_elem.r];
    
    while(i){
        ans[an++]=i;
        i = rev[i];
    }
    printf("%d\n",an);
    for(i=an-1;i>=0;--i){
        printf("%d ",ans[i]);
    }
    return 0;
}