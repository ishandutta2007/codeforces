#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<complex>
#include<vector>
using namespace std;

typedef complex<double> P;
int n,m;
complex<double> A[100000],B[20000];
int R[100000];


bool cmp(int a,int b){
  if(A[a].real()!=A[b].real())return A[a].real()<A[b].real();
  return A[a].imag()<A[b].imag();
}

double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}

int ccw(P a,P b,P c){
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}

int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    A[i]=P(x,y);
    R[i]=i;
  }
  scanf("%d",&m);
  for(int i=0;i<m;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    B[i]=P(x,y);
  }

  sort(R,R+n,cmp);
  vector<P>over,under;
  for(int i=R[0];;i--){
    if(i==-1)i+=n;
    under.push_back(A[i]);
    if(A[i].real()==A[R[n-1]].real())break;
  }
  for(int i=R[n-1];;i--){
    if(i==-1)i+=n;
    over.push_back(A[i]);
    if(A[i].real()==A[R[0]].real())break;
  }
  
  
  bool f=1;
  for(int i=0;f && i<m;i++){
    if(B[i].real()<=under[0].real() || B[i].real()>=over[0].real()){
      f=0;break;
    }
    
    int l,r,c;
    l=0,r=under.size()-1;
    for(;r-l>1;){
      c=(r+l)/2;
      if(B[i].real()<under[c].real())r=c;
      else l=c;
    }
    if(ccw(under[l],under[r],B[i])!=1)f=0;

    r=0,l=over.size()-1;
    for(;l-r>1;){
      c=(r+l)/2;
      if(B[i].real()>over[c].real())l=c;
      else r=c;
    }
    if(ccw(over[r],over[l],B[i])!=1)f=0;

  }
  puts(f?"YES":"NO");
  return 0;
}