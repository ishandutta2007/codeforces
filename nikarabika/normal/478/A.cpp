#include <iostream>

using namespace std;

int main(){
    int s=0;
    for(int i=0; i<5; i++){
        int t;
        cin>>t;
        s+=t;
    }
    if(s%5==0 && s>0)
        cout<<s/5<<endl;
    else
        cout<<-1<<endl;
    return 0;
}