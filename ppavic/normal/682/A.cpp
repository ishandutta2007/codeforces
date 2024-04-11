#include <iostream>

using namespace std;

long long int n,m;

int main(){
    cin >> n >> m;
    long long int sum = 0;
    for(long long int i = 1;i<=n;i++){
        int mod = 5-(i%5);
        long long int cur = 0;
        if(m%5 >= mod){
            cur++;
        }
        sum+=cur+m/5;
    }
    cout << sum << endl;
}