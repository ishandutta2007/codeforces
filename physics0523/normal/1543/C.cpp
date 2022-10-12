#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

map<pi,double> mem;

double a,b,c,d;
int ia,ib,ic,id;
double f(int p,int q){
  p=max(0,p);q=max(0,q);
  if(p==0 && q==0){return 1.0;}
  if(mem[{p,q}]!=0.0){return mem[{p,q}];}
  mem[{p,q}]=1.0;
  double dp=((double)p)/100000.0;
  double dq=((double)q)/100000.0;
  if(p==0){mem[{p,q}]+=dq*f(p,q-id);}
  else if(q==0){mem[{p,q}]+=dp*f(p-id,q);}
  else{
    int del=min(p,id);
    mem[{p,q}]+=dp*f(p-del,q+del/2);
    del=min(q,id);
    mem[{p,q}]+=dq*f(p+del/2,q-del);
  }
  //fprintf(stderr,"%d %d %.12lf\n",p,q,mem[{p,q}]);
  return mem[{p,q}];
}

int main(){
  int t;
  cin >> t;
  while(t>0){
    t--;
    mem.clear();
    cin >> a >> b >> c >> d;

    a*=100000;ia=(int)(a+0.5);
    b*=100000;ib=(int)(b+0.5);
    c*=100000;ic=(int)(c+0.5);
    d*=100000;id=(int)(d+0.5);

    printf("%.12lf\n",f(ia,ib));
  }
  return 0;
}