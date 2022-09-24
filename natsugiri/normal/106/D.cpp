#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
struct MARK_T{
  char c;
  int x,y;
};
vector<MARK_T>v;
vector<pair<char,int> >test;
vector<char>ans;
int main(){
  int n,m,i,j,t,x,y;
  string str;
  MARK_T mark;
  cin>>m>>n;
  bool mat[m][n],b;
  int wlk[2][m][n];

  for(j=0;j<m;j++){
    cin>>str;
    for(i=0;i<n;i++){
      if(str[i]=='#')mat[j][i]=false;
      else mat[j][i]=true;
      if(str[i]!='#'&&str[i]!='.'){
	mark.c=str[i];
	mark.x=i;
	mark.y=j;
	v.push_back(mark);
      }
    }
  }
  cin>>t;
  for(i=0;i<t;i++){
    cin>>str>>j;
    test.push_back(pair<char,int>(str[0],j));
  }
  memset(wlk,-1,sizeof(wlk));
  for(j=1;j<m;j++){
    for(i=1;i<n;i++){
      if(mat[j][i]){
	wlk[0][j][i]=wlk[0][j][i-1]+1;
	wlk[1][j][i]=wlk[1][j-1][i]+1;
      }
    }
  }

  for(i=0;i<v.size();i++){
    x=v[i].x;
    y=v[i].y;
    b=true;
    for(j=0;j<t&&b;j++){
      if(test[j].first=='N'){
	if(wlk[1][y][x]>=test[j].second){
	  y-=test[j].second;
	}else b=0;
      }
      if(test[j].first=='S'){
	if(y+test[j].second<m&&wlk[1][y+test[j].second][x]>=test[j].second){
	  y+=test[j].second;
	}else b=0;
      }
      if(test[j].first=='W'){
	if(wlk[0][y][x]>=test[j].second){
	  x-=test[j].second;
	}else b=0;
      }
      if(test[j].first=='E'){
	if(x+test[j].second<n&&wlk[0][y][x+test[j].second]>=test[j].second){
	  x+=test[j].second;
	}else b=0;
      }
    }
    if(b){
      ans.push_back(v[i].c);
    }
  }
  sort(ans.begin(),ans.end());
  for(i=0;i<ans.size();i++){
    cout<<ans[i];
  }
  if(ans.size()==0){
    cout<<"no solution";
  }
  cout<<endl;
  return 0;
}