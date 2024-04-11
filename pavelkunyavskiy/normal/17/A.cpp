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

bool check(int a){
    if (a<2)
        return false;
    for (int i=2;i*i<=a;i++)
        if (a%i==0)
            return false;
    return true;    
}

bool good[2000];;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  
  int last=-1;
  for (int i=0;i<=1000;i++)
    if (check(i)){
        if (last!=-1)
            good[i+last+1]=true;
        last=i;
    }
    
  for (int i=0;i<=1000;i++)
    if (!check(i))
        good[i]=false;  
    
  int n,k;
  cin>>n>>k;
  int kol=0;
  for (int i=2;i<=n;i++)
    if (good[i])
        kol++;
  if (kol>=k)
    cout<<"YES\n";
  else
    cout<<"NO\n";
  return 0;
}