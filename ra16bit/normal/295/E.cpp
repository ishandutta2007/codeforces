#include <cstdio>
#include <algorithm>
using namespace std;
const int MX=1255555;
int alln,n,m,i,j,N,q[MX][5],x[MX],all[MX];
struct rec { long long cnt,sl,sr,s; } a[MX];
bool u[MX];
void recount(int i, int L, int R, int h) {
  a[i].cnt=a[i*2].cnt+a[i*2+1].cnt;
  a[i].sl=a[i*2].sl+a[i*2+1].sl+a[i*2+1].cnt*(all[h+1]-all[L]);
  a[i].sr=a[i*2].sr+a[i*2+1].sr+a[i*2].cnt*(all[R]-all[h]);
  a[i].s=a[i*2].s+a[i*2+1].s;
  a[i].s+=a[i*2].cnt*(a[i*2+1].cnt*(all[h+1]-all[h])+a[i*2+1].sl);
  a[i].s+=a[i*2+1].cnt*a[i*2].sr;
}
void init(int i, int L, int R) {
  if (L==R) {
    a[i].cnt=int(u[L]);
	a[i].sl=a[i].sr=a[i].s=0;
	return;
  }
  int h=(L+R)/2;
  init(i*2,L,h);
  init(i*2+1,h+1,R);
  recount(i,L,R,h);
}
void modify(int i, int L, int R, int x) {
  if (L==R) {
    a[i].cnt=int(u[L]);
	a[i].sl=a[i].sr=a[i].s=0;
	return;
  }
  int h=(L+R)/2;
  if (x<=h) modify(i*2,L,h,x); else modify(i*2+1,h+1,R,x);
  recount(i,L,R,h);
}
rec count(int i, int L, int R, int l, int r) {
  rec cur;
  cur.cnt=0; cur.sl=0; cur.sr=0; cur.s=0;
  if (l>r) return cur;
  if (L==l && R==r) return a[i];
  int h=(L+R)/2;
  if (l<=h && r>h) {
    rec cur1=count(i*2,L,h,l,h);
	rec cur2=count(i*2+1,h+1,R,h+1,r);
    cur.cnt=cur1.cnt+cur2.cnt;
    cur.sl=cur1.sl+cur2.sl+cur2.cnt*(all[h+1]-all[L]);
    cur.sr=cur1.sr+cur2.sr+cur1.cnt*(all[R]-all[h]);
    cur.s=cur1.s+cur2.s;
    cur.s+=cur1.cnt*(cur2.cnt*(all[h+1]-all[h])+cur2.sl);
    cur.s+=cur2.cnt*cur1.sr;
  } else if (l>h) {
	return count(i*2+1,h+1,R,l,r);
  } else {
    return count(i*2,L,h,l,r);
  }
  return cur;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&x[i]);
	all[i]=x[i];
  }
  alln=n;
  scanf("%d",&m);
  for (i=0; i<m; i++) {
    for (j=0; j<3; j++) scanf("%d",&q[i][j]);
	if (q[i][0]==1) {
	  x[--q[i][1]]+=q[i][2];
	  all[alln++]=x[q[i][1]];
	}
  }
  for (i=0; i<n; i++) x[i]=all[i];
  sort(all,all+alln);
  for (i=0; i<n; i++) u[lower_bound(all,all+alln,x[i])-all]=true;
  for (N=1; N<alln; N*=2);
  init(1,0,N-1);
  for (i=0; i<m; i++) if (q[i][0]==1) {
    int xx=lower_bound(all,all+alln,x[q[i][1]])-all;
    u[xx]=false;
	modify(1,0,N-1,xx);
	x[q[i][1]]+=q[i][2];
	xx=lower_bound(all,all+alln,x[q[i][1]])-all;
	u[xx]=true;
	modify(1,0,N-1,xx);
  } else printf("%I64d\n",count(1,0,N-1,lower_bound(all,all+alln,q[i][1])-all,upper_bound(all,all+alln,q[i][2])-all-1).s);
  return 0;
}