#include <cstdio>
#include <map>

using namespace std;

int n,q;
int pdiv [200010][10];
int pdivn[200010];

int prime[200];
int pn;

void buildPrime(){
    int i,j;
    prime[pn++]=2;
    prime[pn++]=3;
    prime[pn++]=5;
    for(i=7;i<=707;i+=2){
        for(j=0;j<pn;++j) if(!(i%prime[j])) break;
        if(j==pn) prime[pn++]=i;
    }
}

map<int,int> count;
bool adding;
int pobe;
void buildDivisor(int x,int cur,int ind,int curdiv){
    if(ind==pdivn[x]){
        if(!adding) --count[cur];
        if(curdiv&1) pobe+=count[cur];
        else pobe-=count[cur];
        if(adding) ++count[cur];
    } else {
        buildDivisor(x,cur,ind+1,curdiv);
        buildDivisor(x,cur*pdiv[x][ind],ind+1,curdiv+1);
    }
}

bool exist[500010];

int main()
{
    buildPrime();
    scanf("%d%d",&n,&q);
    int i,j;
    bool flag;
    int d;
    for(i=1;i<=n;++i) {
        scanf("%d",&d);
        for(j=0;j<pn;++j){
            flag=!(d%prime[j]);
            while(!(d%prime[j])) d/=prime[j];
            if(flag){
                pdiv[i][pdivn[i]++]=prime[j];
            }
        }
        if(d>1) pdiv[i][pdivn[i]++]=d;
    }
    int x;
    int qi;
    int curcnt=0;
    long long ans=0;
    for(qi=0;qi<q;++qi){
        scanf("%d",&x);
        pobe=0;
        if(exist[x]){
            adding=false;
            buildDivisor(x,1,0,0);
            ans-=-pobe;
            --curcnt;
        } else {
            adding=true;
            buildDivisor(x,1,0,0);
            ans+=-pobe;
            ++curcnt;
        }
        exist[x]=!exist[x];
        printf("%I64d\n",ans);
    }
    return 0;
}