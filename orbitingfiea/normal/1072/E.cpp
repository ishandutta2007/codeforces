#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>a;

struct OPT{
  int a, b, c;
};
vector<OPT>opt;

bool chk(){
  for (int i=a.size()-6;i<a.size();++i)
    if (a[i]) return 0;
  return 1;
}
void lalala(int i,int j){
  a[i*2-j]^=1; a[i]^=1; a[j]^=1;
}
vector<int> lalala(vector<int>a,int i,int j){
  a[i*2-j]^=1; a[i]^=1; a[j]^=1; return a;
}

void gao(){
  int s=a.size()-6, t=a.size();
  for (int i=s-6;i<t;++i)
    for (int j=i+1;j<t;++j){
      if (i*2-j<s-6) continue;
      lalala(i,j);
      if (chk()){
        opt.push_back((OPT){i*2-j,i,j});
        return;
      }
      for (int ii=s-6;ii<t;++ii)
        for (int jj=ii+1;jj<t;++jj){
          if (ii*2-jj<s-6) continue;
          lalala(ii,jj);
          if (chk()){
            opt.push_back((OPT){i*2-j,i,j});
            opt.push_back((OPT){ii*2-jj,ii,jj});
            return;
          }
          lalala(ii,jj);
        }
      lalala(i,j);
    }
  for (int i=s;i<t;++i) printf("%d",a[i]); cout<<endl;
  assert(0);
}

vector<int>b;
queue<vector<int> >q;
map<vector<int>,OPT>pre;

void dfs(){
  pre[a]; q.push(a);
  for (;!q.empty();){
    vector<int>x=q.front(); q.pop();
    if (x==b){
      for (;a!=x;){
        opt.push_back(pre[x]);
        x=lalala(x,pre[x].b,pre[x].c);
      }
      puts("YES");
      cout<<opt.size()<<endl;
      for (auto o:opt) printf("%d %d %d\n",o.a+1,o.b+1,o.c+1);
      exit(0);
    }
    for (int i=0;i<a.size();++i)
      for (int j=i+1;j<a.size();++j){
        if (i*2-j<0) continue;
        vector<int>y=lalala(x,i,j);
        if (!pre.count(y)){
          pre[y]=(OPT){i*2-j,i,j};
          q.push(y);
        }
      }
  }
}

int main(){
  
  cin>>n; a.resize(n);
  for (int i=0;i<n;++i) scanf("%d",&a[i]);
  for (;a.size()>=15;){
    gao();
    a.resize(a.size()-6);
  }
  b.resize(a.size());
  dfs();
  puts("NO");
}