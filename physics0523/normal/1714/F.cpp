#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    int d12,d23,d31;
    cin >> d12 >> d23 >> d31;

    if((d12+d23+d31)%2){cout << "NO\n";continue;}
    if((d12+d23+d31)>2*(n-1)){cout << "NO\n";continue;}

    if(d31>(d12+d23)){cout << "NO\n";continue;}
    if(d12>(d23+d31)){cout << "NO\n";continue;}
    if(d23>(d31+d12)){cout << "NO\n";continue;}

    cout << "YES\n";
    if(d12>=d23 && d12>=d31){
      int out=((d23+d31)-d12)/2;
      int nv=4;
      int ord=d31-out;
      int prev=1;
      for(int i=1;i<=d12;i++){
        if(i==ord){
          if(out==0){
            cout << prev << " " << 3 << "\n";
            prev=3;
          }
          else{
            cout << prev << " " << nv << "\n";
            prev=nv;
            int p2=nv;
            nv++;
            for(int j=1;j<=out;j++){
              if(j==out){
                cout << p2 << " " << 3 << "\n";
              }
              else{
                cout << p2 << " " << nv << "\n";
                p2=nv;
                nv++;
              }
            }
          }
        }
        else if(i==d12){
          cout << prev << " " << 2 << "\n";
        }
        else{
          cout << prev << " " << nv << "\n";
          prev=nv;
          nv++;
        }
      }
      for(int i=nv;i<=n;i++){
        cout << 1 << " " << i << "\n";
      }
    }
    else if(d23>=d12 && d23>=d31){
      int out=((d31+d12)-d23)/2;
      int nv=4;
      int ord=d12-out;
      int prev=2;
      for(int i=1;i<=d23;i++){
        if(i==ord){
          if(out==0){
            cout << prev << " " << 1 << "\n";
            prev=1;
          }
          else{
            cout << prev << " " << nv << "\n";
            prev=nv;
            int p2=nv;
            nv++;
            for(int j=1;j<=out;j++){
              if(j==out){
                cout << p2 << " " << 1 << "\n";
              }
              else{
                cout << p2 << " " << nv << "\n";
                p2=nv;
                nv++;
              }
            }
          }
        }
        else if(i==d23){
          cout << prev << " " << 3 << "\n";
        }
        else{
          cout << prev << " " << nv << "\n";
          prev=nv;
          nv++;
        }
      }
      for(int i=nv;i<=n;i++){
        cout << 2 << " " << i << "\n";
      }
    }
    else{
      int out=((d12+d23)-d31)/2;
      int nv=4;
      int ord=d23-out;
      int prev=3;
      for(int i=1;i<=d31;i++){
        if(i==ord){
          if(out==0){
            cout << prev << " " << 2 << "\n";
            prev=2;
          }
          else{
            cout << prev << " " << nv << "\n";
            prev=nv;
            int p2=nv;
            nv++;
            for(int j=1;j<=out;j++){
              if(j==out){
                cout << p2 << " " << 2 << "\n";
              }
              else{
                cout << p2 << " " << nv << "\n";
                p2=nv;
                nv++;
              }
            }
          }
        }
        else if(i==d31){
          cout << prev << " " << 1 << "\n";
        }
        else{
          cout << prev << " " << nv << "\n";
          prev=nv;
          nv++;
        }
      }
      for(int i=nv;i<=n;i++){
        cout << 3 << " " << i << "\n";
      }
    }
  }
  return 0;
}