#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000001];
int main() {
    int tt;cin>>tt;
    while (tt--){
         int n;cin>>n;
         string s;cin>>s;
         int in1=0,in2=0;
         for (int i=0;i<n;i++){
            if (s[i]=='<') in1++;
            else break;
         }
         for (int i=n-1;i>=0;i--){
            if (s[i]=='>') in2++;
            else break;
         }
         cout<<min(in1,in2)<<endl;

    }
    return 0;
}