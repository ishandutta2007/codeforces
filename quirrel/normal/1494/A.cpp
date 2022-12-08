#include<bits/stdc++.h>
using namespace std;
int f[1009];
main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int A=0,B=0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == s[0]) A++; else
            if(s[i] == s.back()) B++;
        }
        int x = 1;
        if(A > B) x = -1;
        int S = 0, ok =1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == s[0]) S++; else
            if(s[i] == s.back()) S--;
            else S +=x;
        if(S < 0) ok = 0;
        }
        if(S != 0) ok = 0;
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}