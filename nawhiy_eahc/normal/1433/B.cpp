#include <iostream>
using namespace std;

int Book(){
    int n, cnt=0, b=0, result=0;
    cin >> n;
    
    for(int i=1;i<=n;i++){
        int k;
        cin >> k;
        if(k==1) b=1;
        if(b && k==0) cnt++;
        if(b && k==1){
            result+=cnt;
            cnt=0;
        }
    }
    return result;
}

int main(){
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout << Book() << endl;
    }
}