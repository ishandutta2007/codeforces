#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int used[10001];
bool ok(){
   int cur=0;
   for (int i=1;i<=10;i++){
       if (used[i]){
           cur=i;
           break;
       }
   }
   if (cur==0) return true;
   for (int i=cur+1;i<=10;i++){
       if (used[i]!=used[cur] && used[i]) return false;
   }
   return true;
}
int main()
{
    int n;cin>>n;
    bool flag=false;
    int res=1;
    set<int>st;
    for (int i=0;i<n;i++){
        int a;cin>>a;
        used[a]++;
        for (int j=1;j<=10;j++){
            if (used[j]){
                used[j]--;
                if (ok()) {
                    res=i+1;
                    used[j]++;
                    break;
                }
                used[j]++;
            }
        }
    }
    cout<<res;
    return 0;
}