#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#define inf (1 << 30)
using namespace std;

int main(){
    string sum;
    for(int i=1;i<1000;i++){
        string s = to_string(i);
        sum += s;
    }
    int n;
    cin >> n;
    cout << sum[--n];
    return 0;
}