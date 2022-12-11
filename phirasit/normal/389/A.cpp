#include <iostream>
#include <queue>

#define N 110

using namespace std;

priority_queue<int> heap;
int arr[N],n;

int main() {
    
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    while(1) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(arr[i] > arr[j]) {
                    arr[i] %= arr[j];
                    if(arr[i] == 0) arr[i] = arr[j];
                }
            }
        }
        int i;
        for(i=0;i<n-1;i++) {
            if(arr[i] != arr[i+1])
                break;
        }
        if(i >= n-1)
            break;
    }
    int sum = 0;
    for(int i=0;i<n;i++)
        sum += arr[i];
    cout << sum << endl;
    return 0;
}