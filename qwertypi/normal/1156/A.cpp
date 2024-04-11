#include <iostream>
#include <string>
#include <vector>
#include <map>
#define inf (1 << 14)
#define size(x) (int)x.size()
#define pb push_back
using namespace std;
typedef long long ll;
#define MAX 100000
int arr[4][4];
int main(){
    arr[1][1] = inf;
    arr[1][2] = 3;
    arr[1][3] = 4;
    arr[2][1] = 3;
    arr[2][2] = inf;
    arr[2][3] = inf;
    arr[3][1] = 4;
    arr[3][2] = inf;
    arr[3][3] = inf;
    int prev;
    int n;
    cin >> n;
    int A[100];
    cin >> prev;
    A[0] = prev;
    ll ans = 0;
    for(int i=1;i<n;i++){
        int k;
        cin >> k;
        ans += arr[prev][k];
        prev = k;
        A[i] = prev;
    }
    for(int i=0;i<n-2;i++){
        if(A[i] == 3 && A[i+1] == 1 && A[i+2] == 2){
            ans--;
        }
    }
    if(ans >= inf){
        cout << "Infinite";
    }else{
        cout << "Finite" << '\n';
        cout << ans;
    }
    return 0;
}