#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define int64 long long
#define ld long double  
#define setval(a,v) memset(a,v,sizeof(a))
using namespace std;

int t2[1000][1000];
int t5[1000][1000];
int a[1000][1000];

void cnt(int i,int j,int& cnt2,int& cnt5)
{
    cnt2=0;
    for (;(a[i][j]&1)==0;a[i][j]>>=1)
        cnt2++;
    cnt5=0;
    for (;a[i][j]%5==0;a[i][j]/=5)
        cnt5++;
    return ;
}

void print2(int i,int j)
{
    if (i==0 && j==0)
        return;
    if (i==0)
        {
            print2(i,j-1);
            printf("R");
            return;
        }
    if (j==0)
        {
            print2(i-1,j);
            printf("D");
            return ;
        }
    if (t2[i-1][j]<t2[i][j-1])
        {
            print2(i-1,j);
            printf("D");
            return;
        }
    print2(i,j-1);
    printf("R");
}

void print5(int i,int j)
{
    if (i==0 && j==0)
        return;
    if (i==0)
        {
            print5(i,j-1);
            printf("R");
            return;
        }
    if (j==0)
        {
            print5(i-1,j);
            printf("D");
            return  ;
        }
    if (t5[i-1][j]<t5[i][j-1])
        {
            print5(i-1,j);
            printf("D");
            return;
        }
    print5(i,j-1);
    printf("R");
}


int main()
{
  /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif*/
  int n;
  scanf("%d",&n);
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
        scanf("%d",&a[i][j]);
  cnt(0,0,t2[0][0],t5[0][0]);
  int a,b;

  for (int i=1;i<n;i++)
  {
    cnt(0,i,a,b);
    t2[0][i]=t2[0][i-1]+a;
    t5[0][i]=t5[0][i-1]+b;  
  }
  for (int i=1;i<n;i++)
  {
    cnt(i,0,a,b);
    t2[i][0]=t2[i-1][0]+a;
    t5[i][0]=t5[i-1][0]+b;  
  }
  bool q=false;
  int qx=-1, qy=-1;
  for (int i=1;i<n;i++)
    for (int j=1;j<n;j++)
    {
        if (::a[i][j]==0)
        {
             q=true;
             qx=i;
             qy=j;
           a=b=1;
        }
        else
            cnt(i,j,a,b);
        t2[i][j]=min(t2[i-1][j],t2[i][j-1])+a;
        t5[i][j]=min(t5[i-1][j],t5[i][j-1])+b;
          
    }
  if (q && t2[n-1][n-1]!=0 && t5[n-1][n-1]!=0)
  {
    printf("1\n");
    for (int i=0;i<qx;i++)
        printf("D");
    for (int i=0;i<n-1;i++)
        printf("R");
    for (int i=qx;i<n-1;i++)
        printf("D");
    return 0;
  }            
    if (t2[n-1][n-1]<t5[n-1][n-1])
  {
    printf("%d\n",max(t2[n-1][n-1],0));
    print2(n-1,n-1);
  }
  else
    {   
            printf("%d\n",max(t5[n-1][n-1],0));
        print5(n-1,n-1);
    }
  return 0;
}