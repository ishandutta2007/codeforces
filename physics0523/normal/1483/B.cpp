#include<bits/stdc++.h>

using namespace std;
using Graph=vector<deque<int>>;

int gcd(int a,int b){int c;while(b!=0){c=a%b;a=b;b=c;}return a;}

void dcon(deque<int> &a,deque<int> &b){
  if(a.size()>b.size()){
    while(!b.empty()){
      a.push_back(b.front());
      b.pop_front();
    }
  }
  else{
    while(!a.empty()){
      b.push_front(a.back());
      a.pop_back();
    }
    a.swap(b);
  }
}

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
    Graph g(n);
    vector<int> res;
    set<int> st;
    for(int i=0;i<n;i++){
      cin >> a[i];
      g[i].push_back(i);
      st.insert(i);
    }
    int pt=0;
    int magic=0;
    while(res.size()<n && magic<(2*n+5)){
      auto it=st.upper_bound(pt);
      int npt;
      if(it==st.end()){it=st.begin();}
      npt=(*it);
      int fr=g[pt].back(),bk=g[npt].front();
      //cerr << pt << ' ' << npt << ':' << fr << ' ' << bk << '\n';
      if(gcd(a[fr],a[bk])!=1){
        //connect
        if(pt==npt){break;}
        magic++;
        dcon(g[pt],g[npt]);
        st.erase(npt);
        npt=pt;
      }
      else{
        //erase
        magic=0;
        res.push_back(bk+1);
        g[npt].pop_front();
        if(g[npt].size()==0){st.erase(npt);}
      }
      it=st.lower_bound(npt);
      if(it==st.end()){it=st.begin();}
      pt=(*it);
    }
    cout << res.size();
    for(auto &nx : res){cout << ' ' << nx;}cout << '\n';
  }
  return 0;
}