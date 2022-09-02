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

int64 xorall(int64 x){
    if (x==0)
        return 0;
    int64 st2=1;
    for (;st2*2<=x;st2*=2);
    int64 ans=0;
    for (;st2;){
        if (x<=3)
        {
            if (x==2)
                ans+=3;
            if (x==1)
                ans+=1;
            break;          
        }
        if ((x-(st2-1))%2==1)
            ans+=st2;
        x^=st2;
        while (st2>x)
            st2/=2;
    }
    return ans;
}

int64 xorall(int64 a,int64 b){
    return xorall(a)^xorall(b);
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int n;
  scanf("%d",&n);
  int64 x=0;
  for (int i=0;i<n;i++){
    int64 xi,mi;
    cin>>xi>>mi;
    x^=xorall(xi-1,xi+mi-1);    
  }
  if (x==0)
    printf("bolik\n");
  else
    printf("tolik\n");
  return 0;
}