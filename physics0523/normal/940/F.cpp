// Mo_for_3D[jikukan-Mo]
// CFR466-F
// https://codeforces.com/contest/940/submission/150175427

// https://ei1333.hateblo.jp/entry/2017/09/11/211011
// https://kazuma8128.hatenablog.com/entry/2018/03/16/225926

#include<bits/stdc++.h>
#define bsize 2000

using namespace std;

typedef struct{
  int st;
  int fi;
  int tim;
  int id;
}query;

bool qcomp(const query &a,const query &b){
  if((a.tim/bsize)<(b.tim/bsize)){return true;}
  if((a.tim/bsize)>(b.tim/bsize)){return false;}

  int ast=a.st;
  int afi=a.fi;
  int bst=b.st;
  int bfi=b.fi;
  ast/=bsize;bst/=bsize;
  if(ast<bst){return true;}
  if(ast>bst){return false;}
  if((ast&1)==0){
    if(afi<bfi){return true;}
    if(afi>bfi){return false;}
  }
  else{
    if(afi<bfi){return false;}
    if(afi>bfi){return true;}
  }
  return (a.id<b.id);
}

using pi=pair<int,int>;
vector<pi> fw,bw;
int st,fi,tim;
vector<int> work_a;
int bk[262144]={0};
int cc[262144]={0};

void mo_add(int id){
  cc[bk[work_a[id]]]--;
  bk[work_a[id]]++;
  cc[bk[work_a[id]]]++;
}

void mo_rem(int id){
  cc[bk[work_a[id]]]--;
  bk[work_a[id]]--;
  cc[bk[work_a[id]]]++;
}

void mo_time(int fr,int tg){
  pi cp;
  if(fr<tg){cp=fw[fr];}
  else{cp=bw[tg];}

  if(st<=cp.first && cp.first<=fi){mo_rem(cp.first);}
  work_a[cp.first]=cp.second;
  if(st<=cp.first && cp.first<=fi){mo_add(cp.first);}
}

int mo_query(int tst,int tfi,int ttim){
  //cerr << tst << ' ' << tfi << ' ' << ttim << '\n';
  while(tim<ttim){mo_time(tim,tim+1);tim++;}
  while(tim>ttim){mo_time(tim,tim-1);tim--;}
  if(!(fi<tst)){
    while(st<tst){mo_rem(st);st++;}
    while(tst<st){st--;mo_add(st);}
  }
  while(fi<tfi){fi++;mo_add(fi);}
  while(tfi<fi){mo_rem(fi);fi--;}

  while(st<tst){mo_rem(st);st++;}
  while(tst<st){st--;mo_add(st);}
  for(int i=1;;i++){
    if(cc[i]==0){return i;}
  }
  return 1e9;
}

typedef struct{
  int typ;
  int a;
  int b;
}in_q;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin >> n >> q;
  set<int> cp_st;
  vector<int> a(n);
  for(auto &nx : a){
    cin >> nx;
    cp_st.insert(nx);
  }
  vector<in_q> in_qv(q);
  for(auto &nx : in_qv){
    cin >> nx.typ >> nx.a >> nx.b;
    if(nx.typ==1){nx.a--;nx.b--;}
    else{
      nx.a--;
      cp_st.insert(nx.b);
    }
  }

  map<int,int> mp;
  int id=1;
  for(auto &nx : cp_st){
    mp[nx]=id;
    id++;
  }
  for(auto &nx : a){nx=mp[nx];}
  for(auto &nx : in_qv){
    if(nx.typ==2){nx.b=mp[nx.b];}
  }

  vector<query> qv;
  int qid=0,ctm=0;
  vector<int> prea=a;
  for(auto &nx : in_qv){
    if(nx.typ==1){
      qv.push_back({nx.a,nx.b,ctm,qid});
      qid++;
    }
    else{
      fw.push_back({nx.a,nx.b});
      bw.push_back({nx.a,prea[nx.a]});
      prea[nx.a]=nx.b;
      ctm++;
    }
  }

  vector<int> res(qid);
  sort(qv.begin(),qv.end(),qcomp);
  work_a=a;
  mo_add(0);st=0;fi=0;
  for(int i=0;i<qid;i++){
    res[qv[i].id]=mo_query(qv[i].st,qv[i].fi,qv[i].tim);
  }
  for(auto &nx : res){cout << nx << '\n';}
  return 0;
}