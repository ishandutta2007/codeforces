#include <iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int n,a;bool ok=false;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a;
        if(a==1)ok=true;
    }
    if(ok){
        cout<<"HARD";
    }
    else{
        cout<<"EASY";
    }
    return 0;
}