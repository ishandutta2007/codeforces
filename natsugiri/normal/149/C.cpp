#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,a[100000],b[100000];
int show(vector<int>v){
  int i,l=v.size();
  printf("%d\n",l);
  for(i=0;i<l;i++){
    printf("%d%c",v[i]+1,i+1-l?' ':'\n');
  }
  return 0;
}
bool cmp(int x,int y){
  return a[x]>a[y];
}

int main(){
  int i,p,q;
  vector<int>x,y;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",a+i);
    b[i]=i;
  }
  sort(b,b+n,cmp);
  p=q=0;
  for(i=0;i<n;i++){
    if(x.size()<y.size() || x.size()==y.size() && p<q){
      x.push_back(b[i]);
      p+=a[b[i]];
    }else{
      y.push_back(b[i]);
      q+=a[b[i]];
    }
  }
  show(x);show(y);
  return 0;
}