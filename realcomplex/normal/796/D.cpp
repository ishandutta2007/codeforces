#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair

const int N = (int)3e5+9;
vector<pair<int,int>>way[N];
int root[N];
int ans[N];
queue<pair<int,int>>li;

void ini(){
  for(int i = 0;i<N;i++)
    root[i]=-1;
}

int main(){
  ini();
  int n,k,d;
  cin >> n >> k >> d;
  int p;
  for(int i = 0;i<k;i++){
    cin >> p;
    li.push(mp(p,0));
    root[p]=p;
  }
  int a,b;
  for(int i = 1;i<n;i++){
    cin >> a >> b;
    way[a].push_back(mp(b,i));
    way[b].push_back(mp(a,i));
  }
  int cnt = 0;
  int cur,las;
  while(!li.empty()){
    cur=li.front().fi;
    las=li.front().se;
    li.pop();
    for(auto x : way[cur]){
      if(root[x.fi]==-1){
        root[x.fi]=root[cur];
        li.push(mp(x.fi,cur));
      }
      else{
        if(root[x.fi]!=root[cur]){
          if(ans[x.se]!=1){
            ans[x.se]=1;
            cnt++;
          }
        }
      }
    }
  } 
  cout << cnt << "\n"; 
  for(int i = 1;i<n;i++)
    if(ans[i])
      cout << i << " ";
  cout << "\n";
  return 0;
}