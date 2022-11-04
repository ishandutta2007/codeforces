#include <iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        if(i%2==0)cout<<"I hate ";
        else cout<<"I love ";
        if(n-1==i)cout<<"it";
        else cout<<"that ";
    }
    return 0;
}