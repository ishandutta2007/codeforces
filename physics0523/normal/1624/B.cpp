#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long a,b,c;
    cin >> a >> b >> c;
    long long tga=c+2*(b-c);
    if(tga>0 && tga%a==0){cout << "YES\n";continue;}
    long long tgc=a+2*(b-a);
    if(tgc>0 && tgc%c==0){cout << "YES\n";continue;}
    long long tgb=(a+c)/2;
    if((a+c)%2==0 && tgb>0 && tgb%b==0){cout << "YES\n";continue;}
    cout << "NO\n";
  }
  return 0;
}