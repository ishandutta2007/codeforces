#include<bits/stdc++.h>
using namespace std;
typedef string str;
int n,k;
string get[56];
bool ss(str a,str b){
    while(a.size()<b.size())a="0"+a;
    while(b.size()<a.size())b="0"+b;
    return (a>=b);
}
int convert_kt(char c){
    return (c-'0');
}
char convert_so(int a){
    return (char)(a+'0');
}
str char_multi(char c,str a){
    int len=a.size()-1;str kq="";
    int nho=0;
    for(int i=len;i>=0;i--){
        nho+=convert_kt(c)*convert_kt(a[i]);
        kq.insert(0,1,convert_so(nho%10));
        nho/=10;
    }
    if(nho)kq.insert(0,1,convert_so(nho));
    return kq;
}
str cong(str a,str b){
    while(a.size()<b.size())a="0"+a;
    while(a.size()>b.size())b="0"+b;
    int len=a.size()-1,nho=0;str kq="";
    for(int i=len;i>=0;i--){
        int so=convert_kt(a[i])+convert_kt(b[i])+nho;
        nho=0;
        if(so>9){
            nho=so/10;
            so%=10;
        }
        kq.insert(0,1,convert_so(so));
    }
    if(nho)kq.insert(0,1,convert_so(nho));
    return kq;
}
str multi(str a,str b){
    str kq="0";int len=a.size()-1;
    str luu;
    for(int i=len;i>=0;i--){
        luu=char_multi(a[i],b);
        luu.insert(luu.length(),len-i,'0');
        kq=cong(kq,luu);
    }
    return kq;
}
int main(){
    cin>>n;
    get[1]="2";
    for(int i=2;i<=n;i++)get[i]=multi(get[i-1],"2");
    string res="0";
    for(int i=1;i<=n;i++)res=cong(res,get[i]);
    cout<<res;
}