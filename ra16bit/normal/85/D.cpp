#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
struct Node {
  int lft,rgh,cnt;
  long long s[5];
} b[MX*34];
int num,n,i,x;
char s[5];
void mdf(int i, int L, int R, int pos, bool is_add) {
  if (L==R) {
    if (is_add) {
      assert(b[i].cnt==0);
      ++b[i].cnt;
      b[i].s[0]+=pos;
    } else {
      assert(b[i].cnt==1);
      --b[i].cnt;
      b[i].s[0]=0;
    }
    return;
  }
  int mid=(L+R)/2;
  if (pos<=mid) {
    if (b[i].lft==0) b[i].lft=++num;
    mdf(b[i].lft,L,mid,pos,is_add);
  } else {
    if (b[i].rgh==0) b[i].rgh=++num;
    mdf(b[i].rgh,mid+1,R,pos,is_add);
  }
  b[i].cnt=0;
  for (int j=0; j<5; j++) b[i].s[j]=0;
  if (b[i].lft!=0) {
    int x=b[i].lft;
    b[i].cnt+=b[x].cnt;
    for (int j=0; j<5; j++) b[i].s[j]+=b[x].s[j];
  }
  if (b[i].rgh!=0) {
    int st=b[i].cnt%5;
    int x=b[i].rgh;
    b[i].cnt+=b[x].cnt;
    for (int j=0; j<5; j++,st++) {
      if (st>=5) st=0;
      b[i].s[st]+=b[x].s[j];
    }
  }
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s",s);
    if (s[0]=='s') printf("%lld\n",b[0].s[2]); else {
      scanf("%d",&x);
      mdf(0,1,1000000000,x,(s[0]=='a')); 
    }
  }
  return 0;
}