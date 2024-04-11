#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
  int n,x,y,i;
  vector<pair<int,int> >v;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d%d",&x,&y);
    v.push_back(make_pair(x,y));
  }
  sort(v.begin(),v.end());
  x=v[0].second;
  y=0;
  for(i=1;i<n;i++){
    if(v[i].second<x)y++;
    else x=v[i].second;
  }

  printf("%d",y);
}