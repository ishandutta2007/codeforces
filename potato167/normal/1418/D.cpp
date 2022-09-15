#include <bits/stdc++.h>
using namespace std;

int MAX_N=262144;
vector<int64_t> seg(MAX_N*2-1);
int64_t qu_s(int a,int b,int k,int l, int r){
  if(r<=a||b<=l){
    return 0;
  }
  else if(a<=l&&r<=b){
    return seg[k];
  }
  else{
    int64_t X=qu_s(a,b,k*2+1,l,(l+r)/2);
    int64_t Y=qu_s(a,b,k*2+2,(l+r)/2,r);
    return X+Y;
  }
}
int64_t qu(int a,int b){
  return qu_s(a,b,0,0,MAX_N);
}
void pu(int64_t a,int b){
  int D=MAX_N-1+b;
  while(D>0){
    seg[D]+=a;
    D--;
    D/=2;
  }
  seg[0]+=a;
}


int main() {
  int N,Q;
  cin>>N>>Q;
  set<int> s;
  vector<int> p(N);
  vector<pair<int,int>> q(Q);
  for(int i=0;i<N;i++){
    cin>>p[i];
    s.insert(p[i]);
  }
  sort(p.begin(),p.end());
  for(int i=0;i<Q;i++){
    int a,b;
    cin>>a>>b;
    if(a){
      s.insert(b);
    }
    q[i]=make_pair(a,b);
  }
  vector<int> z;
  map<int,int> m;
  for(int x:s){
    z.push_back(x);
  }
  int M=z.size();
  for(int i=0;i<M;i++){
    m[z[i]]=i;
  }
  int l=p[0],r=p[N-1];
  priority_queue<int> pq;
  priority_queue<int> end;
  pq.push(0);
  end.push(-1);
  priority_queue<int> pq_0=pq;
  priority_queue<int> end_0=end;
  for(int i=0;i<N;i++){
    if(i){
      pq.push(p[i]-p[i-1]);
    }
    pu(1,m[p[i]]);
  }
  cout<<r-l-pq.top()<<endl;
  int nl,nr,hi,mi,S=N;
  for(int i=0;i<Q;i++){
    int a,b;
    tie(a,b)=q[i];
    int P=m[b];
    if(a){
      S++;
      if(S==1){
        l=b,r=b;
      }
      else if(b<l){
        pq.push(l-b);
        l=b;
      }
      else if(r<b){
        pq.push(b-r);
        r=b;
      }
      else{
        nl=P,nr=N+Q+10;
        while(nr-nl>1){
          int D=(nl+nr)/2;
          if(qu(P,D)){
            nr=D;
          }
          else{
            nl=D;
          }
        }
        mi=z[nl];
        nl=0,nr=P;
        while(nr-nl>1){
          int D=(nl+nr)/2;
          if(qu(D,P)){
            nl=D;
          }
          else{
            nr=D;
          }
        }
        hi=z[nl];
        end.push(mi-hi);
        pq.push(mi-b);
        pq.push(b-hi);
      }
      pu(1,P);
    }
    else{
      S--;
      if(S==0){
        pq=pq_0;
        end=end_0;
        S=0;
        pu(-1,P);
        cout<<"0"<<endl;
        continue;
      }
      else if(b==l){
        nl=P+1,nr=N+Q+10;
        while(nr-nl>1){
          int D=(nl+nr)/2;
          if(qu(P+1,D)){
            nr=D;
          }
          else{
            nl=D;
          }
        }
        mi=z[nl];
        end.push(mi-b);
        l=mi;
      }
      else if(r==b){
        nl=0,nr=P;
        while(nr-nl>1){
          int D=(nl+nr)/2;
          if(qu(D,P)){
            nl=D;
          }
          else{
            nr=D;
          }
        }
        hi=z[nl];
        end.push(b-hi);
        r=hi;
      }
      else{
        nl=P+1,nr=N+Q+10;
        while(nr-nl>1){
          int D=(nl+nr)/2;
          if(qu(P+1,D)){
            nr=D;
          }
          else{
            nl=D;
          }
        }
        mi=z[nl];
        nl=0,nr=P;
        while(nr-nl>1){
          int D=(nl+nr)/2;
          if(qu(D,P)){
            nl=D;
          }
          else{
            nr=D;
          }
        }
        hi=z[nl];
        pq.push(mi-hi);
        end.push(mi-b);
        end.push(b-hi);
      }
      pu(-1,P);
    }
    while(pq.top()==end.top()){
      pq.pop();
      end.pop();
    }
    cout<<r-l-pq.top()<<endl;
  }
}