#include<bits/stdc++.h>

using namespace std;

long long llgcd(long long a,long long b){long long c;while(b!=0){c=a%b;a=b;b=c;}return a;}

long long dvc(long long x,long long v){
  long long res=0;
  while(x%v==0){x/=v;res++;}
  return res;
}

int main(){
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long p,q;
    cin >> p >> q;
    if((p%q)!=0){cout << p << '\n';continue;}
    long long mem=p;
    for(long long i=2;i*i<=q;i++){
      if((q%i)!=0){continue;}
      long long dvp=dvc(p,i),dvq=dvc(q,i);
      long long ck=1;
      while(dvp>=dvq){ck*=i;dvp--;}
      mem=min(mem,ck);
      while((q%i)==0){q/=i;}
    }
    if(q!=1){
      //cout << q << '\n';
      long long dvp=dvc(p,q),dvq=dvc(q,q);
      long long ck=1;
      while(dvp>=dvq){ck*=q;dvp--;}
      mem=min(mem,ck);
    }
    //cout << mem << '\n';
    cout << (p/mem) << '\n';
  }
  return 0;
}