#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
string s;
int a;
cin>>s>>a;
int b=(s=="back")+1;
if(a==b)cout<<"L";else cout<<"R";
return 0;
}