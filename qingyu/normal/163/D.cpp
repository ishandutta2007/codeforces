#pragma GCC optimize(3)
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstring>
#include <ctype.h>
#include <memory>
#include <fstream>
#include <string>

#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>
#include <set>
//#include <conio.h>
#define oo 2000000000
#define ol 5000000000000000000ll
#define ooo 1E14
#define eps 1E-5
/*#define dis(x1,y1,x2,y2)\
 (double)(sqrt( ((x1)-(x2))*((x1)-(x2)) + ((y1)-(y2))*((y1)-(y2)) ) )
#define disx(x,y) (double)(sqrt((x)*(x)+(y)*(y)))
#define dianji(x1,y1,x2,y2) (double)((x1)*(x2)+(y1)*(y2))
#define chaji(x1,y1,x2,y2) (double)((x1)*(y2)-(y1)*(x2))*/
using namespace std;
const double PI=acos((double)-1);
typedef long long LL;
int ts,ts2;
int n,m;
LL p[50],a[50],mi[50][70], K,V=1;
LL sur ,aa,bb,cc;
double SQR,SQR2;
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}
LL shen[50];
void DFS2(int k,LL la,LL x)
{
     if (x >SQR2) return;
     if (k>K)
     {
            LL u1 =la*(x+V/la/x)+V/la;
         if (u1<sur) sur =u1,aa= la,bb=x;
         return ;
        }
     int i;
     for(i=shen[k];i>=0;i--)
     {
            DFS2(k+1,la ,x*mi[k][i]);
        }
}

void DFS(LL k,LL x)
{ if ((double)x*x*x-eps >V )return ;
  if (k >K)
  {
            double u1 =sqrt((double)V /x),u2 =x*(u1+u1)+u1*u1;
            if (u2>=sur )return;
            SQR2=u1+eps;
            DFS2(1,x,1);
            return ;
        }
     int i;
     for(i=a[k];i>=0;i--)
     {
            shen[k]= a[k]-i;
            DFS(k+1,x*mi[k][i]);
        }
}
int main()
{
  LL i,j,k,t1,t2,t3,t4,t5,t,TES;
  double u1,u2,u3,u4,u5;
  char c1,c2,c3;
  srand((unsigned)time(0));//srand(72888306);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
  #endif
  cin >>TES;
  for(;TES;TES--)
  {
            cin >>K;
            V=1;
            for(i=1;i<=K;i++)
            {
             cin >>p[i]>>a[i];
            }
            
            for(i=1;i<=K;i++)
            {
             t1=1;
             for(j=1;j<=a[i];j++) V *=p[i],t1 *=p[i],mi[i][j] =t1;
             mi[i][0]=1;
            }
            //SQR =pow (V,1./3)+eps;
            t1 =(LL)sqrt(V);
            sur =ol;
            DFS(1,1);
            cc= V/aa/bb;
            cout <<sur *2<<' '<<aa<<' '<<bb<<' '<<cc<<endl;
        }
  return 0;
}