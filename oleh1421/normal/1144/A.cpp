#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void f(string s){
    int c=int(s[0]);
    for (int i=0;i<s.size();i++){
        if (s[i]!=char(c+i)){
            cout<<"NO";
            return;
        }
    }
    cout<<"YES";
}
int main()
{
   int n;cin>>n;
   while (n--){
      string s;cin>>s;
      sort(s.begin(),s.end());
      f(s);
      cout<<endl;
   }
   return 0;
}

/*
7 4
4 7 4 1 2 4 2
*/