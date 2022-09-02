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

int d[1<<24];
int from[1<<24];

map<int,int> dest;
map<int,int> st;
int x[24];
int y[24];
int n;


int cnt(int mask){
//  cerr<<mask<<endl;;
    if (d[mask]!=-1)
        return d[mask];
    if (mask==0)
        return d[mask]=0;
    int fs=mask&(~(mask-1));
    int mask1=mask&(~fs);
    d[mask]=dest[fs]+cnt(mask1);
    from[mask]=fs;
    for (;mask1;){
        int sc=mask1&(~(mask1-1));
        mask1&=(~sc);
        int tmp=cnt(mask & (~fs) & (~sc))+dest[fs|sc];
        if (tmp<d[mask]){
            d[mask]=tmp;
            from[mask]=(fs|sc);
        }
    }
    return d[mask];
}

void print(int mask){
    //cerr<<mask<<" "<<from[mask]<<endl;
    if (mask==0)
        return;
    int tmp=from[mask];
    int fs=st[tmp&~(tmp-1)];
    printf("%d ",fs+1);
    mask&=(~(1<<fs));
    tmp&=(~(1<<fs));
    if (tmp){
        int fs=st[tmp&~(tmp-1)];
        printf("%d ",fs+1);
        mask&=~(1<<fs);
        from[mask]&=~(1<<fs);   
    }
    printf("0 ");
    print(mask);
    return ;    
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int xs,ys;
    scanf("%d %d",&xs,&ys);
  scanf("%d",&n);
  for (int i=0;i<n;i++)
  {
    scanf("%d %d",&x[i],&y[i]);
    x[i]-=xs;
    y[i]-=ys;
    st.insert(mp(1<<i,i));
    dest.insert(mp(1<<i,2*(x[i]*x[i]+y[i]*y[i])));
  }
  for (int i=0;i<n;i++)
    for (int j=i+1;j<n;j++)
        {
            int tmp=x[i]*x[i]+y[i]*y[i];
            tmp+=x[j]*x[j]+y[j]*y[j];
            tmp+=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            dest.insert(mp((1<<i)|(1<<j),tmp));
        }
  setval(d,-1);
  printf("%d\n0 ",cnt((1<<n)-1));
 // cerr<<endl;
    print((1<<n)-1);
  return 0;
}