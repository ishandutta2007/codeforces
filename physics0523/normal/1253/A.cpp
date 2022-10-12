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
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){cin >> a[i];}
    for(int i=0;i<n;i++){cin >> b[i];}
    bool fl=false;
    deque<int> dq;
    for(int i=0;i<n;i++){
      if(a[i]>b[i]){fl=true;}
      dq.push_back(b[i]-a[i]);
    }
    if(fl){cout << "NO\n";continue;}
    while(!dq.empty() && dq.front()==0){dq.pop_front();}
    while(!dq.empty() && dq.back()==0){dq.pop_back();}
    vector<int> mem;
    while(!dq.empty()){
      mem.push_back(dq.front());
      dq.pop_front();
    }
    sort(mem.begin(),mem.end());
    if(mem.size()==0 || mem[0]==mem[mem.size()-1]){cout << "YES\n";}else{cout << "NO\n";}
  }
  return 0;
}