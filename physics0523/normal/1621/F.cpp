#include<bits/stdc++.h>

using namespace std;

bool onlyzero(string &s){
  for(auto &nx : s){
    if(nx!='0'){return false;}
  }
  return true;
}

bool onlyone(string &s){
  for(auto &nx : s){
    if(nx!='1'){return false;}
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,a,b,c;
    cin >> n >> a >> b >> c;
    string s;
    cin >> s;
    if(s.size()==1){cout << "0\n";continue;}
    if(onlyzero(s)){cout << a << '\n';continue;}
    if(onlyone(s)){cout << b << '\n';continue;}

    long long one_ope=0;
    for(int i=1;i<n;i++){if(s[i-1]=='1' && s[i]=='1'){one_ope++;}}
    long long f1,l1;
    for(int i=0;i<n;i++){
      if(s[i]=='1'){f1=i;break;}
    }
    for(int i=n-1;i>=0;i--){
      if(s[i]=='1'){l1=i;break;}
    }
    long long zero_ope=max(0ll,f1-1)+max(0ll,n-1-l1-1);
    long long last_zero=0;
    if(f1!=0){last_zero++;}
    if(l1!=(n-1)){last_zero++;}
    multiset<long long> st;
    long long len=0;
    for(int i=f1;i<=l1;i++){
      if(s[i]=='1'){
        if(len>0){st.insert(len);}
        len=0;
      }
      else{len++;}
    }
    st.insert(1e9);

    long long cres,res=0;
    long long oo,zo;
    long long lz;
    multiset<long long> cst;

    for(int first=0;first<2;first++){
      cres=0;
      oo=one_ope,zo=zero_ope;
      cst=st;
      lz=last_zero;
      for(int i=first;;i++){
        if(i%2){
          if(oo>0){cres+=b;oo--;}
          else{break;}
        }
        else{
          auto it1=cst.find(1);
          auto it2=cst.lower_bound(2);
          if((*it2)<1e8 || zo>0){res=max(cres+a,res);}
          if(oo==0 && it1!=cst.end()){
            cst.erase(it1);
            cres-=c;oo++;
          }
          else if((*it2)<1e8){
            long long mem=(*it2);
            cst.erase(it2);
            cres+=a;
            cst.insert(mem-1);
          }
          else if(zo>0){cres+=a;zo--;}
          else if(it1!=cst.end()){
            cst.erase(it1);
            cres-=c;oo++;
          }
          else if(lz>0){cres-=c;lz--;}
          else{break;}
        }
        res=max(res,cres);
      }
    }

    cout << res << '\n';
  }
  return 0;
}