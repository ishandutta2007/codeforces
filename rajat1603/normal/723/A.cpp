#include "bits/stdc++.h"
using namespace std;
int arr[3];
int main(){
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr , arr + 3);
    cout << arr[1] - arr[0] + arr[2] - arr[1];
}