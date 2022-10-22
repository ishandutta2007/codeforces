#include<bits/stdc++.h>
using namespace std;
int n,p;
string s;
bool check(int v) {
    if(v>=1&&s[v]==s[v-1])return 0;
    if(v>=2&&s[v]==s[v-2])return 0;
    return 1;
}
bool t(int v){
    while(1){
		if(v<0)return 0;
        if(v>=n)return 1;
        if(s[v]-'a'==p-1){
            s[v]='a'-1;v--;
        }else{
            int k=(s[v]-'a'+1)%p;
            s[v]='a'+k;
            if(check(v))v++;
        }
    }
    return 0;
}
int main () {
    cin>>n>>p>>s;
    if(!t(n-1))cout<<"NO";
    else cout<<s;
    return 0;
}