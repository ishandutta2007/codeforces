#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> p(n);
    for(auto &nx : p){cin >> nx;}
    int l=0,r=n-1;
    deque<int> dq;
    while(l<=r){
      if(p[l]<p[r]){
        dq.push_back(p[r]);
        r--;
      }
      else{
        dq.push_front(p[l]);
        l++;
      }
    }
    vector<int> pre;
    while(!dq.empty()){
      pre.push_back(dq.front());
      dq.pop_front();
    }

    deque<int> dq1,dq2;
    l=0,r=n-1;
    while(l<r){
      if(pre[l]<pre[r]){
        dq1.push_front(pre[l]);
        l++;
      }
      else{
        dq1.push_back(pre[r]);
        r--;
      }
    }
    dq2=dq1;
    dq1.push_front(pre[l]);
    dq2.push_back(pre[l]);

    vector<int> v1,v2;
    for(int i=0;i<n;i++){
      v1.push_back(dq1.front());
      dq1.pop_front();
      v2.push_back(dq2.front());
      dq2.pop_front();
    }
    if(p==v1 || p==v2){
      for(int i=0;i<n;i++){
        if(i){cout << ' ';}
        cout << pre[i];
      }cout << '\n';
    }
    else{cout << "-1\n";}
  }
  return 0;
}