#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
    long long n;
    cin >> n;
    deque<long long> A;
    for (long long i = 0; i < n; ++i){
        long long a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());
    deque<long long> B = A;
    long long ans = 0;
    while (B.size() && A.size()){
        while (B.size() && B.back() >= A.back())
            B.pop_back();
        if (B.size() == 0)
            break;
        ++ans;
        B.pop_back();
        A.pop_back();
    }
    cout << ans;
    return 0;
}