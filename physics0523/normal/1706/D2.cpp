#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    // n=100000;k=99999;

    vector<int> bk(100005,0);
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      // v=i+1;
      bk[v]=1;
    }

    int maxa=0;
    vector<int> a;
    for(int i=0;i<100005;i++){
      if(bk[i]>0){
        a.push_back(i);
        maxa=i;
      }
    }

    if(maxa<k){cout << "0\n";continue;}

    n=a.size();

    vector<int> p(n,1);
    vector<vector<int>> g(100010);
    vector<int> work(100010,0);
    priority_queue<int> pq;
    int mi=1e9;

    for(int i=0;i<n;i++){
      int v=a[i]/p[i];
      g[v].push_back(i);
      mi=min(mi,v);
      if(work[v]==0){
        pq.push(v);
        work[v]=1;
      }
    }

    int res=1e9;
    while(!pq.empty()){
      int ma=pq.top();pq.pop();
      res=min(res,ma-mi);

      bool kill=false;
      for(auto &id : g[ma]){
        int c=a[id]/p[id];
        int x;
        if(a[id]%c==0){x=(a[id]/c)+1;}
        else{x=ceil(a[id],c);}
        if(x>k){kill=true;break;}

        p[id]=x;

        c=a[id]/p[id];
        if(work[c]==0){
          pq.push(c);
          work[c]=1;
        }
        g[c].push_back(id);
        mi=min(mi,c);
      }

      // g[ma].clear(); // bad
      vector<int>().swap(g[ma]); // good
      if(kill){break;}
    }

    cout << res << '\n';
  }
  return 0;
}