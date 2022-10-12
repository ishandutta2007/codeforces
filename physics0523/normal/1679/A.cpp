#include<bits/stdc++.h>

using namespace std;

long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    if(n%2){cout << "-1\n";continue;}
    if(n<4){cout << "-1\n";continue;}
    cout << llceil(n,6) << ' ';
    cout << (n/4) << '\n';
  }
  return 0;
}