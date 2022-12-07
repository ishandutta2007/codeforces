#include <bits/stdc++.h>
using namespace std;
string s;long long res=0;
int main(){
    cin>>s;
    s=" "+s;
    for(int i=1;i<s.size();i++){
        int num=s[i]-'0';
        if(num%4==0)res++;
        int k=s[i-1]-'0';
        k=k*10+num;
        if(k%4==0)res+=i-1;
    }
    cout<<res;
}