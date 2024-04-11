#include <bits/stdc++.h>
#define MAXN 1007
using namespace std;
int n,b[MAXN],a[MAXN],o[15000000];
bool tk[MAXN];
void fail()
{
    printf("NO");
    exit(0);
}
void out()
{
    printf("YES\n");
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    exit(0);
}
int main()
{
    int odd=0,even=0;
    vector<int> ev,od;
    cin>>n;
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++)
    {
        if(b[i]&1) {odd++; od.push_back(i);}
        else {even++; ev.push_back(i);}
    }
    if(n==2)
    {
        if(b[0]!=b[1]) fail();
        printf("YES\n%d %d",b[0],0); exit(0);
    }
    if(odd==1 && even==2) fail();
    if(even!=0)
    {
        int a1=ev[0],b1,c1;
        if(odd>=2) {b1=od[0]; c1=od[1];}
        else {b1=ev[1]; c1=ev[2];}
        a[0]=(b[b1]+b[c1]-b[a1])/2;
        int cnt=1;
        for(int i=0;i<n;i++) if(i!=a1) a[cnt++]=b[i]-a[0];
        out();
    }
    int ns=min(n,26),m1=-1,m2;
    for(int k=0;k<(1<<ns);k++) if(__builtin_popcount(k)==ns/2)
    {
        int s=0;
        for(int z=0;z<ns;z++) if((1<<z) & k) s+=b[z];
        if(o[s]!=0)
        {
            m1=o[s];
            m2=k;
            break;
        }
        o[s]=k;
    }
    if(m1==-1) fail();
    int x=m1&m2;
    m1^=x; m2^=x;
    vector<int> e1,e2;
    for(int i=0;i<ns;i++) if((1<<i)&m1) e1.push_back(i);
    for(int i=0;i<ns;i++) if((1<<i)&m2) e2.push_back(i);
    a[0]=0;
    int cnt=1,cur=0;
    for(int i=0;i<e1.size();i++)
    {
        tk[e1[i]]=true;
        tk[e2[i]]=true;
        cur=b[e1[i]]-cur;
        a[cnt++]=cur;
        cur=b[e2[i]]-cur;
        a[cnt++]=cur;
    }
    cnt--;
    for(int i=0;i<n;i++) if(!tk[i]) a[cnt++]=b[i];
    out();
}