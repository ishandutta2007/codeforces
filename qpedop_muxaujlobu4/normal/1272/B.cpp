#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include <string>
using namespace std;
long long a[4];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    long long t;
    cin>>t;
    for(long long  i=0;i<t;++i){
        for(int i=0;i<4;++i)a[i]=0;
        cin>>s;
    int len=s.length();
    for(int i=0;i<len;++i){
        if(s[i]=='U')++a[0];
        if(s[i]=='D')++a[1];
        if(s[i]=='L')++a[2];
        if(s[i]=='R')++a[3];
    }
    a[0]=min(a[0],a[1]);
    a[1]=min(a[0],a[1]);
    a[2]=min(a[2],a[3]);
    a[3]=min(a[2],a[3]);
    if(a[0]==0&&a[2]>0){
       cout<<2<<endl;
       cout<<"RL"<<endl;
       continue;
    }
    if(a[0]>0&&a[2]==0){
        cout<<2<<endl;
        cout<<"UD"<<endl;
        continue;
    }
    if(a[0]==0&&a[2]==0){
        cout<<0<<endl;
    }
    else{
        cout<<(2*a[0]+2*a[2])<<endl;
        for(int i=0;i<a[0];++i)cout<<'U';
        for(int i=0;i<a[2];++i)cout<<'R';
        for(int i=0;i<a[0];++i)cout<<'D';
        for(int i=0;i<a[2];++i)cout<<'L';
        cout<<endl;
    }
    }
    return 0;
}