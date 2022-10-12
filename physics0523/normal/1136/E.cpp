#include<bits/stdc++.h>

using namespace std;

#define bsize 524288

long long sum_raw(long long i,long long bit[]){
  long long s=0;
  while(i>0){
    s+=bit[i];
    i-=i&(-i);
  }
  return s;
}
void add_raw(long long i,long long x,long long bit[]){
  while(i<=bsize){
    bit[i]+=x;
    i+=i&(-i);
  }
}

long long bitsg_raw[bsize+5]={0},bitd_raw[bsize+5]={0};

void raq_raw(long long st,long long fi,long long x){
  add_raw(st,-(x*(st-1)),bitsg_raw);
  add_raw(fi+1,(x*fi),bitsg_raw);
  add_raw(st,x,bitd_raw);
  add_raw(fi+1,-x,bitd_raw);
}

long long rsq_raw(long long st,long long fi){
  st--;
  long long stv,fiv;
  fiv=sum_raw(fi,bitsg_raw)+sum_raw(fi,bitd_raw)*fi;
  stv=sum_raw(st,bitsg_raw)+sum_raw(st,bitd_raw)*st;
  return fiv-stv;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    long long v;
    cin >> v;
    raq_raw(i,i,v);
  }
  
  set<int> st;
  vector<long long> k(n);
  for(int i=1;i<n;i++){
    st.insert(i);
    cin >> k[i];
  }
  st.insert(n);

  int query;
  cin >> query;
  while(query>0){
    query--;
    string s;
    long long p,q;
    cin >> s >> p >> q;
    if(s[0]=='s'){cout << rsq_raw(p,q) << '\n';}
    else{
      if(p!=1){st.insert(p-1);}
      int fi=p;
      auto fit=st.lower_bound(fi);
      fi=(*fit);
      while(fi<n){
        auto it=st.lower_bound(fi+1);
        int nfi=(*it);
        long long fs=rsq_raw(fi,fi)+q+k[fi];
        long long bs=rsq_raw(fi+1,fi+1);
        if(fs>bs){
          st.erase(fi);
          long long dlt=fs-q-bs;
          raq_raw(fi+1,nfi,dlt);
        }
        else{break;}
        fi=nfi;
      }
      raq_raw(p,fi,q);
    }
  }
  return 0;
}