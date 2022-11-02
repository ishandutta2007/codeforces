#include<stdio.h>
#include<map>
#include<string>
using namespace std;
char tmp[1000];
map<string,int> XD;
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
    scanf("%s",tmp);
    XD[tmp]++;
    }
    map<string,int>::iterator it;
    int ma=0;
    for(it=XD.begin();it!=XD.end();it++)
    if(ma<it->second)ma=it->second;
    for(it=XD.begin();it!=XD.end();it++)
    if(ma==it->second)puts((it->first).c_str());
}