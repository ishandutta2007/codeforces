#include <bits/stdc++.h>
using namespace std;
const int MX=144144;
struct Node {
  int a,b,c,ab,bc,abc;
} b[2*MX];
int n,q,pos;
char s[MX],c[5];
void recalc(int i) {
  b[i].a=b[i*2].a+b[i*2+1].a;
  b[i].b=b[i*2].b+b[i*2+1].b;
  b[i].c=b[i*2].c+b[i*2+1].c;
  b[i].ab=min(b[i*2].a+b[i*2+1].ab,b[i*2].ab+b[i*2+1].b);
  b[i].bc=min(b[i*2].b+b[i*2+1].bc,b[i*2].bc+b[i*2+1].c);
  b[i].abc=min(b[i*2].a+b[i*2+1].abc,b[i*2].ab+b[i*2+1].bc);
  b[i].abc=min(b[i].abc,b[i*2].abc+b[i*2+1].c);
}
void init(int i, int L, int R) {
  if (L==R) {
    char cur=s[R-1];
    b[i].a=int(cur=='a');
    b[i].b=int(cur=='b');
    b[i].c=int(cur=='c');
    return;
  }
  int mid=(L+R)/2;
  init(i*2,L,mid);
  init(i*2+1,mid+1,R);
  recalc(i);
}
void mdf(int i, int L, int R, int pos, char cur) {
  if (L==R) {
    s[R-1]=cur;
    b[i].a=int(cur=='a');
    b[i].b=int(cur=='b');
    b[i].c=int(cur=='c');
    return;
  }
  int mid=(L+R)/2;
  if (pos<=mid) mdf(i*2,L,mid,pos,cur); else mdf(i*2+1,mid+1,R,pos,cur);
  recalc(i);
}
int main() {
  scanf("%d%d",&n,&q);
  scanf("%s",s);
  init(1,1,n);
  while (q--) {
    scanf("%d",&pos);
    scanf("%s",c);
    mdf(1,1,n,pos,c[0]);
    printf("%d\n",b[1].abc);
  }
  return 0;
}