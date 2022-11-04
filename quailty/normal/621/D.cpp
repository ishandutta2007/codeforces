
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
typedef long double ldb;
const ldb eps=1e-9;
const char s[12][15]=
{
    "x^y^z",
    "x^z^y",
    "(x^y)^z",
    "(x^z)^y",
    "y^x^z",
    "y^z^x",
    "(y^x)^z",
    "(y^z)^x",
    "z^x^y",
    "z^y^x",
    "(z^x)^y",
    "(z^y)^x"
};
ldb t[12],r[12];
int main()
{
    db tx,ty,tz;
    scanf("%lf%lf%lf",&tx,&ty,&tz);
    ldb x=tx,y=ty,z=tz;
    t[0]=z*log(y);
    t[1]=y*log(z);
    t[2]=t[3]=log(y)+log(z);
    t[4]=z*log(x);
    t[5]=x*log(z);
    t[6]=t[7]=log(x)+log(z);
    t[8]=y*log(x);
    t[9]=x*log(y);
    t[10]=t[11]=log(x)+log(y);
    r[0]=r[1]=r[2]=r[3]=log(x);
    r[4]=r[5]=r[6]=r[7]=log(y);
    r[8]=r[9]=r[10]=r[11]=log(z);
    bool flag=0;
    for(int i=0;i<12;i++)
        flag|=(r[i]>0);
    int loc=11;
    if(!flag)
    {
        for(int i=0;i<12;i++)r[i]=-r[i];
        for(int i=11;i>=0;i--)
            if(r[i]==0 || t[i]+log(r[i])<t[loc]+log(r[loc])+eps)
                loc=i;
    }
    else
    {
        for(int i=11;i>=0;i--)
            if(r[i]>0)
            {
                loc=i;
                break;
            }
        for(int i=11;i>=0;i--)
            if(r[i]>0 && t[i]+log(r[i])>t[loc]+log(r[loc])-eps)
                loc=i;
    }
    printf("%s",s[loc]);
    return 0;
}