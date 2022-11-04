#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int gcd(int a,int b)
{
    return b==0 ? a : gcd(b,a%b);
}
struct frac
{
    int a,b;// a/b
    void nor()
    {
        if(a==0)b=1;
        else if(b==0)a=1;
        else
        {
            int g=gcd(a,b);
            a/=g;
            b/=g;
            if(a<0)
            {
                a=-a;
                b=-b;
            }
        }
    }
    bool operator < (const frac &p)const
    {
        return a==p.a ? b<p.b : a<p.a;
    }
};
frac build(int _a,int _b)
{
        frac t;
        t.a=_a; t.b=_b;
        t.nor();
        return t;
}
set<frac>cnt;
int main()
{
    int n;
    scanf("%d",&n);
    int x0,y0;
    scanf("%d%d",&x0,&y0);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        cnt.insert(build(x-x0,y-y0));
    }
    printf("%d",cnt.size());
    return 0;
}