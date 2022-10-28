#include<iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    for(int i = 1 ; i < 100 ; i += 2){
        int cur = 0;
        for(int j = 1 ; j <= i ; ++j){
            cur += (i>>1) + (j&1);
        }
        if(cur>=x){
            cout<<((x==3)?5:i);
            return 0;
        }
    }
}