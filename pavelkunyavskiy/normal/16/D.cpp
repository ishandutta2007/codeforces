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

int readtime(){
        string s;
        getline(cin,s);
        int h,m;
        char c;
        sscanf(s.data(),"[ %d:%d %c.m]",&h,&m,&c);
        if (h==12)
                h=0;
        int time=h*60+m;
        if (c=='p')
                time+=12*60;
        return time;
}

int a[100];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int n;
  scanf("%d\n",&n);
  for (int i=0;i<n;i++)
        a[i]=readtime();
  int ans=1;
  int t=0;
  int ptr=0;
  for (;;t++){
    if (t==60*24)
    {
        ans++;
        t=0;
    }
    for (int i=0;i<10 && ptr<n && a[ptr]==t;++ptr,++i);
    if (ptr==n)
        break;
  }  
  cout<<ans<<endl;
  return 0;
}