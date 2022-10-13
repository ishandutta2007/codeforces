#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define d 12

using namespace std;

int dx9[16]={0,-1,-1,-1,0,0,1,1,1};
int dy9[16]={0,-1,0,1,-1,1,-1,0,1};

int n;

int f1(int x,int y){return x;}
int f2(int x,int y){return y;}
int f3(int x,int y){return (y-x);}

int dist(int x1,int y1,int x2,int y2){
  int xd=x2-x1;
  int yd=y2-y1;
  if(xd<0 && yd<0){xd*=-1;yd*=-1;}
  if(xd>0 && yd>0){return max(xd,yd);}
  return (max(xd,-xd)+max(yd,-yd));
}

int x[524288]={0},y[524288]={0};

int res(int ix,int iy){
  int i,r=0;
  for(i=0;i<n;i++){r=max(dist(ix,iy,x[i],y[i]),r);}
  return r;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int i,j,k,l;
  
  int mi,miv;
  int ma,mav;
  
  int rx,ry,rv,px,py,pv;

  int w;
  int st,fi,te1,te2;
  int te1x,te1y,te1v,te2x,te2y,te2v;
  
  cin >> n;
  for(i=0;i<n;i++){
    string str;
    cin >> str;
    l=str.size();
    for(j=0;j<l;j++){
      if(str[j]=='B'){x[i]++;}
      else{y[i]++;}//'N'
    }
    //cout << x[i] << ' ' << y[i] << '\n';
  }
  rx=1;ry=1;rv=res(rx,ry);
  for(i=0;i<5;i++){
      for(j=0;j<5;j++){
          if(i+j==0){continue;}
          px=i;py=j;pv=res(i,j);
          if(pv<rv){rv=pv;rx=px;ry=py;}
      }
  }
  
  mi=0;miv=f1(x[0],y[0]);
  ma=0;mav=f1(x[0],y[0]);
  for(i=1;i<n;i++){
    if(f1(x[i],y[i])<miv){mi=i;miv=f1(x[i],y[i]);}
    if(f1(x[i],y[i])>mav){ma=i;mav=f1(x[i],y[i]);}
  }

  for(i=-d;i<=d;i++){
    w=((miv+mav)/2)+i;
    st=0;fi=1000000;
    while(st<=fi){
      te1=(st*2+fi)/3;
      te2=(st+fi*2)/3;
      
      te1x=w;te1y=te1;
      if(te1x<0||te1y<0){st=te1+1;continue;}
      te1v=res(te1x,te1y);
      if(te1v<rv){rv=te1v;rx=te1x;ry=te1y;}
      
      te2x=w;te2y=te2;
      if(te2x<0||te2y<0){fi=te2-1;continue;}
      te2v=res(te2x,te2y);
      if(te2v<rv){rv=te2v;rx=te2x;ry=te2y;}

      if(te1v>te2v){st=te1+1;continue;}
      fi=te2-1;
    }
  }

  mi=0;miv=f2(x[0],y[0]);
  ma=0;mav=f2(x[0],y[0]);
  for(i=1;i<n;i++){
    if(f2(x[i],y[i])<miv){mi=i;miv=f2(x[i],y[i]);}
    if(f2(x[i],y[i])>mav){ma=i;mav=f2(x[i],y[i]);}
  }
  
  for(i=-d;i<=d;i++){
    w=((miv+mav)/2)+i;
    st=0;fi=1000000;
    while(st<=fi){
      te1=(st*2+fi)/3;
      te2=(st+fi*2)/3;
      
      te1x=te1;te1y=w;
      if(te1x<0||te1y<0){st=te1+1;continue;}
      te1v=res(te1x,te1y);
      if(te1v<rv){rv=te1v;rx=te1x;ry=te1y;}
      
      te2x=te2;te2y=w;
      if(te2x<0||te2y<0){fi=te2-1;continue;}
      te2v=res(te2x,te2y);
      if(te2v<rv){rv=te2v;rx=te2x;ry=te2y;}
      
      if(te1v>te2v){st=te1+1;continue;}
      fi=te2-1;
    }
  }

  mi=0;miv=f3(x[0],y[0]);
  ma=0;mav=f3(x[0],y[0]);
  for(i=1;i<n;i++){
    if(f3(x[i],y[i])<miv){mi=i;miv=f3(x[i],y[i]);}
    if(f3(x[i],y[i])>mav){ma=i;mav=f3(x[i],y[i]);}
  }

  for(i=-d;i<=d;i++){
    w=((miv+mav)/2)+i;
    st=0;fi=1000000;
    while(st<=fi){
      te1=(st*2+fi)/3;
      te2=(st+fi*2)/3;
      
      te1x=te1;te1y=w+te1;
      if(te1x<0||te1y<0){st=te1+1;continue;}
      te1v=res(te1x,te1y);
      if(te1v<rv){rv=te1v;rx=te1x;ry=te1y;}
      
      te2x=te2;te2y=w+te2;
      if(te2x<0||te2y<0){fi=te2-1;continue;}
      te2v=res(te2x,te2y);
      if(te2v<rv){rv=te2v;rx=te2x;ry=te2y;}

      if(te1v>te2v){st=te1+1;continue;}
      fi=te2-1;
    }
  }
  
  cout << rv << '\n';
  for(i=0;i<rx;i++){cout << 'B';}
  for(i=0;i<ry;i++){cout << 'N';}
  cout << '\n';
  return 0;
}