                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
#include <set>
using namespace std;

#define int64 long long
#define P pair<int, int>

int n, cnt;
int arr[200][2];

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    int a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
        for(int j = 0; j < i; j++){
            if(arr[i][0] == arr[j][1])
                cnt++;
            if(arr[j][0] == arr[i][1])
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}