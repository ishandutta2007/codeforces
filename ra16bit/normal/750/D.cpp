#include <bits/stdc++.h>
using namespace std;
const int dx[8]={0,1,1,1,0,-1,-1,-1};
const int dy[8]={1,1,0,-1,-1,-1,0,1};
const int MD=150,MX=MD*2,MQ=MX*MX*30*20;
int n,i,x,y,w,pos,d,cnt,c[31],fi,fr,q[MQ],v[MQ/30],cur;
bool was[MX][MX];
inline void add(int x, int y, int w, int pos, int d) {
  d/=2;
  cur=(((x*MX+y)*n+w)*5+pos)*4+d;
  int e=cur/30,o=cur%30;
  if (((v[e]>>o)&1)==0) {
    v[e]|=(1<<o);
	q[fr++]=cur;
  }
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&c[i]);
  q[fi=0]=cur=(MD*MX+MD)*n*20;
  fr=v[0]=1;
  while (fi<fr) {
    cur=q[fi++];
	d=(cur%4)*2; cur/=4;
	pos=cur%5;   cur/=5;
	w=cur%n;     cur/=n;
	y=cur%MX;
	x=cur/MX;
	if (w&1) ++d;
	if (!was[x][y]) {
	  was[x][y]=true;
	  ++cnt;
	}
	if (pos+1<c[w]) {
	  add(x+dx[d],y+dy[d],w,pos+1,d);
	} else if (w+1<n) {
	  if (--d<0) d=7;
	  add(x+dx[d],y+dy[d],w+1,0,d);
	  d=(d+2)%8;
	  add(x+dx[d],y+dy[d],w+1,0,d);
	}
  }
  printf("%d\n",cnt);
  return 0;
}