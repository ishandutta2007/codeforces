#include <iostream>
using namespace std;
int main(){
    int t,x=0;
    cin>>t;
    for (int i=0; i<t; i++){
        string s;
        cin>>s;
        if (s=="X++" or s=="++X"){
            x+=1;
        }
        else{
            x-=1;
        }
    }
    cout<<x;
}