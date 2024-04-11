#include<iostream>
#include<algorithm>
using namespace std;
int n,cnt,k;
long long a[100005],b,m;
main(){
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> m;
    if(m%2 == 0) b+=m;
    else a[cnt++] = m;
  }
  sort(a,a+cnt);
  if(cnt%2!=0) k=1;
  for(int i=cnt-1;i>=k;i--){
    b+=a[i];
  }
  cout << b << "\n";
  return 0;
}