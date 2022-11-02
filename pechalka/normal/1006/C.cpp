#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long long n;
    cin >> n;
    deque<pair<long long, long long>> A = {{0, 0}};
    deque<pair<long long, long long>> B = {{0, 0}};
    long long sum1 = 0, sum2 = 0;
    vector<long long> D(n);
    for (int i = 0; i < n; ++i){
        cin >> D[i];
        sum1 += D[i];
        A.push_back({sum1, i + 1});
    }
    for (int i = 0; i < n; ++i){
        sum2 += D[n - i - 1];
        B.push_back({sum2, i + 1});
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    while (A.back().first != B.back().first || (A.back().second + B.back().second > n)){

        if (A.back().first > B.back().first)
            A.pop_back();
        else if (B.back().first > A.back().first)
            B.pop_back();
        else{
            A.pop_back();
            B.pop_back();
        }
            
    }
    cout << A.back().first;
    return 0;
}