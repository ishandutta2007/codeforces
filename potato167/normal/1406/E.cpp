#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,Z=1;
  cin>>N;
  int M=N;
  vector<int> p(N+1,1);
  vector<int> q;
  for(int i=2;i<=N;i++){
    if(p[i]){
      q.push_back(i);
      if(N/i<i-1){
        continue;
      }
      for(int j=i;i*j<=N;j++){
        p[j*i]=0;
      }
    }
  }
  q.push_back(100003);
  int x=0,a;
  while(q[x]*q[x]<=N/Z){
    cout<<"B "<<q[x]<<endl;
    cin>>a;
    M-=a;
    cout<<"A "<<q[x]<<endl;
    cin>>a;
    if(a){
      M++;
      int s=q[x];
      while(s*q[x]<=N){
        s*=q[x];
        cout<<"A "<<s<<endl;
        cin>>a;
        if(a==0){
          s/=q[x];
          break;
        }
      }
      Z*=s;
    }
    x++;
  }
  if(q[x]>N/Z){
    cout<<"C "<<Z<<endl;
    return 0;
  }
  int b=lower_bound(q.begin(),q.end(),1+N/Z)-q.begin();
  b--;
  x=max(x-1,0);
  int l=x,r=b;
  while(r-l>1){
    int D=(l+r)/2;
    for(int i=l+1;i<=D;i++){
      cout<<"B "<<q[i]<<endl;
      cin>>a;
      M-=a;
    }
    cout<<"A 1"<<endl;
    cin>>a;
    if(a==M){
      l=D;
    }
    else{
      M=a;
      r=D;
    }
  }
  if(q[l]>N){
    cout<<"C "<<Z<<endl;
    return 0;
  }
  cout<<"B "<<q[l]<<endl;
  cin>>a;
  cout<<"A "<<q[l]<<endl;
  cin>>a;
  if(a&&Z%q[l]){
    Z*=q[l];
  }
  if(q[r]>N){
    cout<<"C "<<Z<<endl;
    return 0;
  }
  cout<<"B "<<q[r]<<endl;
  cin>>a;
  cout<<"A "<<q[r]<<endl;
  cin>>a;
  if(a&&Z%q[r]){
    Z*=q[r];
  }
  cout<<"C "<<Z<<endl;
}