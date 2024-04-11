#include<bits/stdc++.h>
using namespace std;
int main(){
    string x = "CODEFORCES";
    int n = x.size();
    string a;
    cin>>a;
    int l = a.size();
    if(l >= n){
        for(int i=0;i<=n;++i){
            if(a.substr(0, i) + a.substr(l-(n-i)) == x){
               printf("YES");
               return 0;
            }
        }
    }
    printf("NO");
}