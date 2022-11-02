#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <iomanip>
#define inf (1 << 30)
typedef long long ll;
using namespace std;

int A[51][51];
int B[51][51];
int main(){
    for(int i=0;i<51;i++){
        A[0][i] = A[i][0] = B[i][0] = B[0][i] = -inf;
    }
    int r, c;
    cin >> r >> c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> A[i][j];
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> B[i][j];
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            int A_min = max(A[i][j-1], A[i-1][j])+1;
            int B_min = max(B[i][j-1], B[i-1][j])+1;
            if((A_min > B_min) ^ (A[i][j] > B[i][j])){
                swap(A[i][j], B[i][j]);
            }
            if(A[i][j] < A_min || B[i][j] < B_min){
                cout << "Impossible";
                return 0;
            }
        }
    }
    cout << "Possible";
    return 0;
}