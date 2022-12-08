                /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define P pair<int, int>

int n;
int arr[1010];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    for(int i = 0; i < n; i++){
        if(arr[i] > arr[0]){
            cout << arr[i] << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}