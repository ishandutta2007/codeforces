#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    if(n==1 && s[0]=='0') cout << "No";
    else if(n==1 && s[0]=='1') cout << "Yes";
        
   else if(s[0]==s[1] && s[0]=='0') cout << "No";
 else  if(s[n-2]==s[n-1] && s[n-1]=='0') cout << "No";
    
 else {
        for(int i=0;i<n-1;i++) if(s[i]==s[i+1] && s[i]=='1') {  cout << "No"; return 0; }     
        for(int i=0;i<n-2;i++) if(s[i]==s[i+1] && s[i+1]==s[i+2] && s[i]=='0') { cout << "No"; return 0;}                     
                                                                          
     cout << "Yes";
                              
             }
}