#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int used[1001];
bool ok(string s){
     for (int i=1;i<(int)s.size();i++){
        if (abs(s[i]-s[i-1])==1) return 0;
     }
     return 1;
}
void F(string r){
    for (int i=1;i<=700;i++){
        random_shuffle(r.begin(),r.end());
        if (ok(r)){
            string res="";
            for (auto i:r){
                for (int j=0;j<used[int(i)];j++) res+=i;
            }
            cout<<res<<endl;
            return;
        }
    }
    cout<<"No answer"<<endl;
}
int main()
{
   int t;cin>>t;
   while (t--){
      string s;cin>>s;
      set<char>st;
      for (auto i:s) {
         st.insert(i);
         used[int(i)]++;
      }
      string r="";
      for (auto i:st) r+=i;
      F(r);
      for (int i=int('a');i<=int('z');i++) used[i]=0;
   }
   return 0;
}