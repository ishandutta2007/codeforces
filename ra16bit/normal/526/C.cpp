#include <cstdio>
#include <algorithm>
using namespace std;
int c,hr,hb,wr,wb;
long long cur,i,r;
int main() {
  scanf("%d%d%d%d%d",&c,&hr,&hb,&wr,&wb);
  if (wr<wb) { swap(wr,wb); swap(hr,hb); }
  cur=wr;
  if (cur*cur>=c) {
    for (i=0; i*cur<=c; i++) r=max(r,i*hr+(c-i*cur)/wb*hb);
  } else {
    for (i=0; i*cur<=c && i<=wb; i++) r=max(r,i*hr+(c-i*cur)/wb*hb);
    swap(wr,wb); swap(hr,hb); cur=wr;
    for (i=0; i*cur<=c && i<=wb; i++) r=max(r,i*hr+(c-i*cur)/wb*hb);
  }
  printf("%I64d\n",r);
  return 0;
}