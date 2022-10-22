#include <iostream>

using namespace std;

int main(){
    long long int n;
    cin >> n;
    long long int result=1;
    for(long long int i=1;i<n;i++){
        result*=i;
    }
    result=result/(n/2);
    
    cout << result;
    
    return 0;
}