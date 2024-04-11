#include <iostream>

using namespace std;

int boring(){
    int k,dight,result=0, cnt=1;
    cin >> k;
    dight=k%10;
    result+=10*(dight-1);
    while(k!=0){
        k/=10;
        result+=cnt++;
    }
    
    return result;
}

int main(){
    int t;
    cin >> t;
    
    for(int i=1;i<=t;i++){
        cout << boring() << endl;
    }
}