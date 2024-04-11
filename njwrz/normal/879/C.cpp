#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a,b,p;
	string s;
    cin>>n;
    a=0,b=1023;
    for(int i=0;i<n;i++){
        cin>>s>>p;
        if(s[0]=='|'){
            a|=p;b|=p;
        }else if(s[0]=='^'){
            a^=p;b^=p;
        }else{
            a&=p;b&=p;
        }
    }
    int ans1=0,ans2=0;
    for(int i=0;i<10;i++){
        int a1=a&(1<<i);
        int b1=b&(1<<i);
        if(a1&&b1){
            ans1|=(1<<i);
        }
        if(a1&&!b1){
            ans2|=(1<<i);
        }
        if(!a1&&!b1){
            ans1|=(1<<i);ans2|=(1<<i);
        }
    }
    cout<<"2"<<'\n';
    cout<<"| "<<ans1<<'\n';
    cout<<"^ "<<ans2;
}