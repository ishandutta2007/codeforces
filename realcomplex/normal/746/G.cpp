#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = (int)2e5 + 9;
vector<int>Layer[N];
int edge[N];
int min_leaf[N];
int max_leaf[N];

int main(){
  fastIO;
  int n,t,k;
  cin >> n >> t >> k;
  for(int i = 1;i<=t;i++)cin >> edge[i];
  int p = 1;
  Layer[0].push_back(p);
  for(int i = 1;i<=t;i++){ 
    for(int j = 0;j<edge[i];j++){
      p++;
      Layer[i].push_back(p);
    }
  }
  int cl = 0,cr = 0;
  for(int j = 1;j<t;j++){
    max_leaf[j]=edge[j]-1;
    min_leaf[j]=max(edge[j]-edge[j+1],0);
    cl +=min_leaf[j];
    cr+=max_leaf[j];
  }
  max_leaf[t]=edge[t];
  min_leaf[t]=edge[t];
  cl+=edge[t],cr+=edge[t];
  if(k < cl or k > cr){
    cout << -1 << "\n";
    return 0;  
  }
  cout << n << "\n";
  int extra;
  int m;
  for(auto x : Layer[1])cout << x << " " << 1 << "\n";
  for(int i = 1;i<t;i++){
    extra = min(k-cl,max_leaf[i]-min_leaf[i]);
    cl+=extra;
    m = min_leaf[i]+extra;
    p = 0;
    for(int j = m;j<Layer[i].size();j++){
      cout << Layer[i][j] << " " << Layer[i+1][p]<<"\n";
      p++;
    }
    while(p<Layer[i+1].size()){
      cout << Layer[i][m] << " " << Layer[i+1][p] << "\n";
      p++;
    }
  }
  return 0;
}