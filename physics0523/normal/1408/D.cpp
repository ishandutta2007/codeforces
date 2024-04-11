#include<bits/stdc++.h>
#define inf 1072114514

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  int a[2048],b[2048],c[2048],d[2048];
  int dcov[2097152]={0};
  
  for(int i=0;i<n;i++){
    cin >> a[i] >> b[i];
  }
  for(int i=0;i<m;i++){
    cin >> c[i] >> d[i];
    dcov[c[i]]=d[i];
  }

  for(int i=2097151;i>=1;i--){dcov[i-1]=max(dcov[i-1],dcov[i]);}
  
  int arr[1048576];
  for(int i=0;i<1048576;i++){arr[i]=0;}

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(a[i]>c[j]){continue;}
      int lim=(c[j]-a[i]);
      arr[lim]=max(dcov[c[j]]-b[i]+1,arr[lim]);
      //cout << lim << ' ' << dcov[c[j]]-b[i]+1 << '\n';
    }
  }
  
  int res=inf;
  for(int i=1048575;i>=1;i--){
    arr[i-1]=max(arr[i-1],arr[i]);
    res=min(arr[i]+i,res);
  }
  res=min(arr[0],res);
  cout << res;
  return 0;
}