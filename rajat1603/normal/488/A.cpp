#include<iostream>
using namespace std;
bool check(int a){
    if(a<0){
        a*=-1;
    }
    while(a){
        int temp=a%10;
        if(temp==8){
            return 1;
        }
        a/=10;
    }
    return 0;
}
int main(){
    int a;
    cin>>a;
    int b = 1;
    a++;
    while(check(a)!=1){
        b++;
        a++;
    }
    cout<<b;
}