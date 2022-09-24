#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  int n,i,j,cnt;
  vector<int>v;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    int t;
    scanf("%d",&t);
    v.push_back(-t);
  }

  bool f=1;
  for(;f;){
    f=0;
    sort(v.begin(),v.end());
    for(;v.back()==0;)v.pop_back();
    n=v.size();
    j=v[0];
    cnt=1;
    for(i=1;i<n;i++){
      if(v[i]==j){
	cnt++;
	if(cnt>n/3){
	  v[i]=0;
	  f=1;
	}
      }else{
	j=v[i];
	cnt=1;
      }
    }
  }
  if(n<3)puts("0");
  else{
    int a[n/3][3];
    for(i=0;i<(n/3)*3;i++){
      a[i%(n/3)][i/(n/3)]=v[i];
    }
    printf("%d\n",n/3);
    for(j=0;j<n/3;j++){
      for(i=0;i<3;i++){
	printf("%d%c",-a[j][i],i==2?'\n':' ');
      }
    }
  }
  return 0;
}