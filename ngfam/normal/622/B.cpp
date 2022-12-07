#include <bits/stdc++.h>
using namespace std;
string s;
int a,h,m,res;
int main(){
    cin>>s;
    cin>>a;
    h=((s[0]-'0')*10)+s[1]-'0';
    m=((s[3]-'0')*10)+s[4]-'0';
    h+=(a/60);
    if(h>23)h=h%24;
    a=a%60;
    res=a+m;
    if(res>=60){
        res-=60;
        h++;
    }
    if(h>23)h-=24;
    if(h<10)cout<<"0";
    cout<<h<<":";
    if(res<10)cout<<"0";
    cout<<res;
}