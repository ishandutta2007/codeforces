#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int k, n1, n2, n3, t1, t2, t3;
priority_queue<int, vector<int>, greater<int>> q1, q2, q3;

int z;

int main() {
    cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
    for (int i = 0; i < n1; i++) q1.push(0);
    for (int i = 0; i < n2; i++) q2.push(0);
    for (int i = 0; i < n3; i++) q3.push(0);
    for (int i = 0; i < k; i++) {
        int a = q1.top();
        int b = q2.top();
        int c = q3.top();
        q1.pop(); q2.pop(); q3.pop();
        if (a >= b && a >= c) {
            q1.push(a+t1);
            q2.push(a+t2);
            q3.push(a+t3);
            z = max(z, a+t1+t2+t3);
        } else if (b >= a && b >= c) {
            q1.push(b+t1);
            q2.push(b+t2);
            q3.push(b+t3);
            z = max(z, b+t1+t2+t3);
        } else {
            q1.push(c+t1);
            q2.push(c+t2);
            q3.push(c+t3);
            z = max(z, c+t1+t2+t3);
        }
    }
    cout << z << "\n";
}