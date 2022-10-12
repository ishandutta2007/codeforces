#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l;
    cin >> l;
    string s;
    cin >> s;
    set<string> st;
    for(int i=0;i<l;i++){
      st.insert({s[i]});
      if(i>=1){st.insert({s[i-1],s[i]});}
      if(i>=2){st.insert({s[i-2],s[i-1],s[i]});}
    }

    bool ao=false;
    for(int i=0;i<26;i++){
      string cs={(char)('a'+i)};
      if(st.find(cs)==st.end()){cout << cs << '\n';ao=true;break;}
    }
    if(ao){continue;}

    ao=false;
    for(int i=0;i<26*26;i++){
      string cs={(char)('a'+(i/26)),(char)('a'+(i%26))};
      if(st.find(cs)==st.end()){cout << cs << '\n';ao=true;break;}
    }
    if(ao){continue;}

    ao=false;
    for(int i=0;i<26*26*26;i++){
      string cs={(char)('a'+i/(26*26)),(char)('a'+(i%(26*26))/26),(char)('a'+i%26)};
      if(st.find(cs)==st.end()){cout << cs << '\n';ao=true;break;}
    }
    if(ao){continue;}
  }
  return 0;
}