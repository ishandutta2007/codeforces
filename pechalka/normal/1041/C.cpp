#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
    long long n, m, d;
    cin >> n >> m >> d;
    vector<pair<long long, long long>> A (n);
    for (int i = 0; i < n; ++i){
        long long a;
        cin >> a;
        A[i] = {a, i};
    }
    sort(A.begin(), A.end());
    deque<long long> q;
    vector<long long> dayNeed;
    vector<long long> wichDay (n);
    for (int i = 0; i < n; ++i){
        if (q.size() && dayNeed[q.front()] <= A[i].first){
            dayNeed[q.front()] = A[i].first + d + 1;
            wichDay[A[i].second] = q.front();
            q.pop_front();
            if (dayNeed[wichDay[A[i].second]] <= m)
                q.push_back(wichDay[A[i].second]);
        }else {
            wichDay[A[i].second] = dayNeed.size();
            dayNeed.push_back(A[i].first + d + 1);
            q.push_back(dayNeed.size() - 1);
        }
    }
    cout << dayNeed.size() << endl;
    for (int i = 0; i < n; ++i)
        cout << wichDay[i] + 1 << " ";
}