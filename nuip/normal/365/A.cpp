#include <bits/stdc++.h>

#define reep(i, s, n) for( int i = s; i < n; ++i )
#define rep(i, n) reep(i, 0, n)

using namespace std;

int main()
{
  int n, k;
  int cnt = 0;

  cin >> n >> k;
  string st="0123456789";
  rep(i, n){
    string str;
    cin >> str;
    sort(str.begin(),str.end());
    str.erase(unique(str.begin(),str.end()),str.end());
    //cout<<str<<endl;
    cnt+=(str.substr(0,k+1)==st.substr(0,k+1));
    /*
    int flag[10] = { 0 };
    rep(j, str.size()){
      int idx = str[j] - '0';
      flag[idx]++;
    }
    
    bool isOk = true;
    rep(j, k+1){
      if( flag[j] != 1 ){
	isOk = false;
      }
    }
    reep(j, k+1, 10){
      if( flag[j] != 0 ) {
	isOk = false;
      }
    }
    if( isOk ){
      ++cnt;
      }*/
  }

  cout << cnt << endl;
}