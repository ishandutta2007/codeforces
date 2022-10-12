#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i=0;i<h;i++){cin >> s[i];}
    vector<vector<int>> fl(h,vector<int>(w,0));
    vector<vector<int>> d(h,vector<int>(w,0));
    int id=1;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(fl[i][j]==0){
          int ci=i,cj=j;
          while(1){
            if(ci<0 || h<=ci || cj<0 || w<=cj){break;}
            if(fl[ci][cj]!=0){
              if(fl[ci][cj]!=id){ci=-1;cj=-1;}
              break;
            }
            fl[ci][cj]=id;
            if(s[ci][cj]=='U'){ci--;}
            else if(s[ci][cj]=='D'){ci++;}
            else if(s[ci][cj]=='L'){cj--;}
            else if(s[ci][cj]=='R'){cj++;}
          }
          if(!(ci<0 || h<=ci || cj<0 || w<=cj)){
            int ti=ci,tj=cj,cl=0;
            do{
              //cerr << ci << ' ' << cj << '\n';
              cl++;
              if(s[ci][cj]=='U'){ci--;}
              else if(s[ci][cj]=='D'){ci++;}
              else if(s[ci][cj]=='L'){cj--;}
              else if(s[ci][cj]=='R'){cj++;}
            }while(ci!=ti || cj!=tj);
            do{
              //cerr << ci << ',' << cj << '\n';
              d[ci][cj]=cl;
              if(s[ci][cj]=='U'){ci--;}
              else if(s[ci][cj]=='D'){ci++;}
              else if(s[ci][cj]=='L'){cj--;}
              else if(s[ci][cj]=='R'){cj++;}
            }while(ci!=ti || cj!=tj);
          }
        }
        id++;
      }
    }
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        //cerr << i << ' ' << j << '\n';
        if(d[i][j]==0){
          stack<pair<int,int>> st;
          int ci=i,cj=j;
          int dd;
          while(1){
            //cerr << ci << ',' << cj << '\n';
            if(ci<0 || h<=ci || cj<0 || w<=cj){dd=1;break;}
            if(d[ci][cj]!=0){dd=d[ci][cj]+1;break;}
            st.push({ci,cj});
            if(s[ci][cj]=='U'){ci--;}
            else if(s[ci][cj]=='D'){ci++;}
            else if(s[ci][cj]=='L'){cj--;}
            else if(s[ci][cj]=='R'){cj++;}
          }
          while(!st.empty()){
            pair<int,int> od=st.top();st.pop();
            d[od.first][od.second]=dd;
            dd++;
          }
        }
      }
    }
    int rh=1,rw=1,rd=-1;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(rd<d[i][j]){rd=d[i][j];rh=i;rw=j;}
      }
    }
    cout << rh+1 << ' ' << rw+1 << ' ' << rd << '\n';
  }
  return 0;
}