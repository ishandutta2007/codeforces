#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,Z=0,a,b,c,d;
  cin>>N;
  vector<int> p(N);
  queue<int> q;
  for(int i=0;i<N;i++){
    q.push(i+1);
  }
  vector<int> r(N);
  for(int i=0;i<N-1;i++){
    a=q.front();
    q.pop();
    b=q.front();
    q.pop();
    cout<<"? "<<a<<" "<<b<<endl;
    cin>>c;
    cout<<"? "<<b<<" "<<a<<endl;
    cin>>d;
    if(c<d){
      swap(c,d);
      swap(a,b);
    }
    if(c==d){
      Z=1;
      break;
    }
    else if(r[c]){
      Z=1;
      break;
    }
    else{
      r[c]=1;
      p[a-1]=c;
      q.push(b);
    }
  }
  p[q.front()-1]=N;
  if(Z){
    cout<<"! -1"<<endl;
  }
  else{
    cout<<"! ";
    for(int i=0;i<N;i++){
      cout<<p[i];
      if(i!=N-1){
        cout<<" ";
      }
    }
    cout<<endl;
  }
}