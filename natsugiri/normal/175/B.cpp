#include<cstdio>
#include<iostream>
#include<string>
#include<map>

using namespace std;

int n;
map<string, int>mp;


int main(){
  
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    string s;
    int x;
    cin>>s>>x;
    mp[s]=max(mp[s], x);
  }
  
  int m=mp.size();
  printf("%d\n", m);
  for(__typeof(mp.end())it=mp.begin(); it!=mp.end(); it++){
    int w=0;
    for(__typeof(mp.end())t=mp.begin(); t!=mp.end(); t++)
      if((*it).second < (*t).second)w++;

    cout<<(*it).first<<' ';
    if(m*50 < w*100)puts("noob");
    else if(m*20 < w*100)puts("random");
    else if(m*10 < w*100)puts("average");
    else if(m*1 < w*100)puts("hardcore");
    else puts("pro");
  }
  return 0;
}