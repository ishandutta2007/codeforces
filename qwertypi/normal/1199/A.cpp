#include <iostream>
#include <algorithm>
using namespace std;

int A[100000];
int main(){
    int n,x, y;
    cin >> n >> x >> y;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    for(int i=0;i<n;i++){
        if(*min_element(A + max(0, i-x), A + min(n, i+y+1)) == A[i]){
            cout << i + 1;
            return 0;
        }
    }
    return 0;
}