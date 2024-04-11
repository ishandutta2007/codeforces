#include<bits/stdc++.h>

using namespace std;

int n,qc=0;
int ask(int l,int r){
  qc++;
  if(n<l){return 0;}
  r=min(n,r);
  printf("? %d %d\n",l,r);
  fflush(stdout);
  int res;
  scanf("%d",&res);
  return (r-l+1)-res;
}

void ans(int res){
  printf("! %d\n",res);
  fflush(stdout);
}

int main(){
  int t;
  scanf("%d%d",&n,&t);
  int tg;
  scanf("%d",&tg);

  int siz=262144;
  vector<int> arr(1);
  arr[0]=ask(1,siz);

  int cnt=1;
  int bs=262144;
  while(bs>32){
    cnt*=2;
    bs/=2;
    vector<int> narr(cnt);
    for(int i=0;i<cnt;i++){
      if(i%2==0){narr[i]=ask(bs*i+1,bs*(i+1));}
      else{narr[i]=arr[i/2]-narr[i-1];}
    }
    arr.swap(narr);
  }

  //cerr << bs << '\n';
  for(int i=1;i<cnt;i++){arr[i]+=arr[i-1];}

  while(t>0){
    t--;

    int st=0,fi=cnt-1,te;
    while(st<=fi){
      te=(st+fi)/2;
      if(arr[te]<tg){st=te+1;}else{fi=te-1;}
    }
    
    int sl=bs*st+1;
    int cpk=st;
    
    st=0;fi=bs-2;
    while(st<=fi){
      te=(st+fi)/2;
      if(ask(1,sl+te)<tg){st=te+1;}else{fi=te-1;}
    }
    ans(sl+st);
    for(int i=cpk;i<cnt;i++){arr[i]--;}
    if(t!=0){scanf("%d",&tg);}
  }
  return 0;
}