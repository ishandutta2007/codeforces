#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m,x,y;
int a[100000],b[100000];

pair<int,int> v[100000];
pair<int,int> w[100000];
vector<pair<int,int> >ans;



int main(){
  int i,j;
  scanf("%d%d%d%d",&n,&m,&x,&y);
  for(i=0;i<n;i++)scanf("%d",a+i);
  for(i=0;i<m;i++)scanf("%d",b+i);

  for(i=j=0;i<n&&j<m;i++){
    for(;j<m && b[j]<a[i]-x;)j++;
    if(j<m && a[i]-x<=b[j] && b[j]<=a[i]+y){
      ans.push_back(make_pair(i,j));
      j++;
    }
  }
  printf("%d\n",ans.size());
  for(i=0;i<(int)ans.size();i++){
    printf("%d %d\n",ans[i].first+1,ans[i].second+1);
  }
  return 0;
}