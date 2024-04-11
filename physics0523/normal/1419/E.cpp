#include<bits/stdc++.h>

using namespace std;

bool plfl[1048600];

long long lim=1048576;

void sieve_of_erat(){
  long long i,j;
  for(i=0;i<lim+5;i++){plfl[i]=true;}
  plfl[0]=false;
  plfl[1]=false;
  for(i=2;i<lim;i++){
    if(!plfl[i]){continue;}
    for(j=2*i;j<lim;j+=i){
      plfl[j]=false;
    }
  }
  return;
}

void prarr(int arr[],int n){
  int i;
  for(i=0;i<n;i++){
    if(i){cout << ' ';}
    cout << arr[i];
  }
  cout << '\n';
  return;
}

int main(){
  sieve_of_erat();
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  int res[262144],rc;
  scanf("%d",&t);

  while(t>0){
    t--;rc=0;
    int n;
    scanf("%d",&n);
    set<int> st;
    st.insert(n);
    for(int i=2;i*i<=n;i++){
      if(n%i){continue;}
      st.insert(i);
      st.insert(n/i);
    }
    set<int> cst=st,nst;
    int pmem[64],pmc=0;
    while(!cst.empty()){
      nst.clear();
      int fl=1;
      for(auto x:cst){
        if(fl){pmem[pmc]=x;pmc++;fl=0;}
        else if(x%pmem[pmc-1]){nst.insert(x);}
      }
      cst=nst;
    }

    int rv;
    if(pmc>=3){
      rv=0;
      for(int i=0;i<pmc;i++){
        st.erase(pmem[i]*pmem[(i+1)%pmc]);
      }
      for(int i=0;i<pmc;i++){
        set<int> lef;
        for(auto x: st){
          if(x%pmem[i]==0){
            res[rc]=x;
            rc++;
          }
          else{lef.insert(x);}
        }
        st.swap(lef);
        res[rc]=pmem[i]*pmem[(i+1)%pmc];
        rc++;
      }
    }
    else if(pmc==1){
      rv=0;
      for(auto x: st){
        res[rc]=x;rc++;
      }
    }
    else{
      if(st.size()==3){
        rv=1;
        for(auto x: st){res[rc]=x;rc++;}
      }
      else{
        rv=0;
        int g=pmem[0]*pmem[1];
        int k1=-1,k2=-1;
        set<int> lef;
        for(auto x: st){
          if(k2!=-1){lef.insert(x);}
          if(x%g==0){
            if(k1==-1){k1=x;}
            else if(k2==-1){k2=x;}
            else{lef.insert(x);}
          }
          else{lef.insert(x);}
        }
        st.clear();
        for(auto x: lef){
          if(x%pmem[0]){st.insert(x);}
          else{
            res[rc]=x;rc++;
          }
        }
        res[rc]=k1;rc++;
        for(auto x: st){
          res[rc]=x;rc++;
        }
        res[rc]=k2;rc++;
      }
    }
    prarr(res,rc);
    cout << rv << '\n';
  }
  return 0;
}