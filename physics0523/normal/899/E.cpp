#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);

  for(int i=0;i<n;i++){cin >> a[i];}
  priority_queue<pi> pq;
  set<pi> st;
  int cc=1;
  for(int i=0;i<n;i++){
    if(i==n-1 || a[i]!=a[i+1]){
      pq.push(make_pair(cc,-i));
      st.insert(make_pair(i,cc));
      cc=1;
    }
    else{cc++;}
  }
  int res=0;
  while(!pq.empty()){
    pi od=pq.top();pq.pop();
    od.second*=-1;
    pi sq=make_pair(od.second,od.first);
    if(st.find(sq)==st.end()){continue;}
    res++;
    st.erase(sq);
    auto it=st.lower_bound(sq);
    if(it==st.begin() || it==st.end()){continue;}
    pi md2=(*it);
    it--;
    pi md1=(*it);
    if(a[md1.first]!=a[md2.first]){continue;}
    st.erase(md1);st.erase(md2);
    md1.second+=md2.second;
    st.insert(md1);
    pq.push(make_pair(md1.second,-md1.first));
  }
  cout << res << '\n';
  return 0;
}