#include <iostream>
#include <deque>

using namespace std;

int main(){
    long long n, m;
    deque<long long> C;
    deque<long long> A;
    cin >> n >> m;
    for (int i = 0; i < n; ++i){
        long long a;
        cin >> a;
        C.push_back(a);
    }
    for (int i = 0; i < m; ++i){
        long long a;
        cin >> a;
        A.push_back(a);
    }
    for (int i = 0; i < n; ++i){
        if (A.size()){
            if (C.front() <= A.front()){
                A.pop_front();
            }
            C.pop_front();
        }    
    }
    cout << m - A.size();
    return 0;
}