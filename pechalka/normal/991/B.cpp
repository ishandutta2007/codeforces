#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, sum = 0;
    cin >> n;
    int A[6] = {0, 0, 0, 0, 0, 0};
    for (int i = 0; i < n; ++i){
        int a;
        cin >> a;
        A[a]++;
        sum += a;
    }
    int i = 2, ans = 0;
    while (sum * 10 < n * 45){
        if (A[i] < 1)
            ++i;
        else{
            --A[i];
            ++A[5];
            sum += 5 - i;
            ++ans;
        }
    }
    cout << ans;
    return 0;
}