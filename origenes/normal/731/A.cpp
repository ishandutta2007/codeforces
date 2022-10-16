#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    int len=s.length();
    char pos='a';
    int cnt=0;
    for(int i=0; i<len; i++){
        int l=abs(s.at(i)-pos);
        int r=26-l;
        //if(r<0) r+=26;
        //cout<<l<<' '<<r<<' '<<min(l, r)<<endl;
        cnt+=min(l, r);
        pos=s.at(i);
    }
    cout<<cnt<<endl;
    return 0;
}