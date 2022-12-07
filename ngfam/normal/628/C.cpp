#include <bits/stdc++.h>
using namespace std;
string s;int n,k;

int main(){
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i<s.size();i++){
        if(s[i]-'a'>'z'-s[i]){
            int f=min(k,s[i]-'a');
            s[i]=s[i]-f;
            k-=f;
        }
        else{
            int f=min(k,'z'-s[i]);
            s[i]=s[i]+f;
            k-=f;
        }
    }
    if(k>0)cout<<-1;
    else cout<<s;
}