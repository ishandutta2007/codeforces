#include<bits/stdc++.h>

using namespace std;

int arr1[16]={1,11,101,1009,10007,100003,1000003,10000019,100000007};
int arr2[16]={2,13,103,1013,10009,100019,1000033,10000079,100000037};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int a,b,c;
    cin >> a >> b >> c;
    int g=arr1[c-1];
    int x=arr1[a-c];
    int y=arr2[b-c];
    cout << g*x << ' ' << g*y << '\n';
  }
  return 0;
}