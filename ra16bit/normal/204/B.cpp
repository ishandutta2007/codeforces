#include <cstdio>
#include <map>
using namespace std;
int a,b,x,y,n,h,i,r=-1;
map<int,int> good,bad;
map<int,int>::iterator it;
int main() {
  scanf("%d",&n);
  h=(n+1)/2;
  for (i=0; i<n; i++) {
    scanf("%d%d",&a,&b);
    good[a]++;
    if (a!=b) bad[b]++;
  }
  for (it=good.begin(); it!=good.end(); it++) {
    x=it->second;
    y=bad[it->first];
    if (x+y>=h && (r==-1 || max(0,h-x)<r)) r=max(0,h-x);
  }
  for (it=bad.begin(); it!=bad.end(); it++) {
    x=good[it->first];
    y=it->second;
    if (x+y>=h && (r==-1 || max(0,h-x)<r)) r=max(0,h-x);
  }
  printf("%d\n",r);
  return 0;
}