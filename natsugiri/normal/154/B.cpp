#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;


const int NUM=100010;
bool on[NUM];

vector<int>primeFactors(int n){
  int i;
  vector<int>res;
  for(i=2;i*i<=n;i++){
    if(n%i==0){
      res.push_back(i);
      for(;n%i==0;){n/=i;}
    }
  }
  if(n>1)res.push_back(n);
  return res;
}

int main(){
  int n,m,i,j;
  memset(on,0,sizeof on);

  vector<int>nnn(NUM,0);
  vector<int>f;
  bool b;
  scanf("%d%d",&n,&m);
  for(i=0;i<m;i++){
    b=0;
    char s[99],c;
    int x;
    scanf("%s%d",s,&x);
    c=s[0];
    f=primeFactors(x);
    if(x==1){
      if(c=='+'){
	if(on[1])puts("Already on");
	else puts("Success");
	on[1]=1;
	nnn[1]=1;
      }else{
	if(on[1])puts("Success");
	else puts("Already off");
	on[1]=0;
	nnn[1]=0;
      }
    }else{
      if(c=='+'){
	for(j=0;j<(int)f.size();j++){
	  if(on[f[j]]==1){
	    if(nnn[f[j]]==x)puts("Already on");
	    else printf("Conflict with %d\n",nnn[f[j]]);
	    b=1;
	    break;
	  }
	}
	if(!b){
	  for(j=0;j<(int)f.size();j++){
	    nnn[f[j]]=x;
	    on[f[j]]=1;
	  }
	  puts("Success");
	}
      }else{
	for(j=0;j<(int)f.size();j++){
	  if(on[f[j]]==0||nnn[f[j]]!=x){
	    puts("Already off");
	    b=1;
	    break;
	  }
	}
	if(!b){
	  for(j=0;j<(int)f.size();j++){
	    on[f[j]]=0;
	    nnn[f[j]]=0;
	  }
	  puts("Success");
	}
      }
    }
  }
  return 0;
}