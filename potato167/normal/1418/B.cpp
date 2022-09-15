#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin>>T;
  for(int i=0;i<T;i++){
    int N;
    cin>>N;
    vector<int> p(N);
    vector<int> q(N);
    for(int i=0;i<N;i++){
      cin>>p[i];
    }
    for(int i=0;i<N;i++){
      cin>>q[i];
    }
    vector<int> r;
    for(int i=0;i<N;i++){
      if(!q[i]){
        r.push_back(p[i]);
      }
    }
    sort(r.begin(),r.end());
    reverse(r.begin(),r.end());
    vector<int> z(N);
    int x=0;
    for(int i=0;i<N;i++){
      if(q[i]){
        z[i]=p[i];
      }
      else{
        z[i]=r[x];
        x++;
      }
    }
    for(int i=0;i<N;i++){
      cout<<z[i];
      if(i!=N-1){
        cout<<" ";
      }
      else{
        cout<<endl;
      }
    }
  }
}