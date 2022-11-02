#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    long long a[n];
    int pts[n];
    priority_queue<pair<long long, int> > q;
    long long sumdiff, sum;
    sumdiff = 0;
    sum = 0;

    for(int i = 0; i<n; i++){
        cin >> a[i];
        pts[i] = 1;
        sum += a[i]*a[i];

        if(a[i] >= pts[i] + 1){
            long long d_n = (a[i] / (pts[i] + 1));
            long long l_n = (a[i] % (pts[i] + 1));
            long long k_n = pts[i] + 1 - l_n;

            long long d_o = (a[i] / (pts[i]));
            long long l_o = (a[i] % (pts[i]));
            long long k_o = pts[i] - l_o;

            long long diff = k_o*d_o*d_o+l_o*(d_o + 1)*(d_o + 1) - k_n*d_n*d_n-l_n*(d_n + 1)*(d_n + 1);
            q.push({diff, i});

        }
    }

    for(int j = 0; j<k - n; j++){
        auto x = q.top();
        q.pop();
        sumdiff += x.first;

        int i = x.second;
        pts[i]++;

        if(a[i] >= pts[i] + 1){
            long long d_n = (a[i] / (pts[i] + 1));
            long long l_n = (a[i] % (pts[i] + 1));
            long long k_n = pts[i] + 1 - l_n;

            long long d_o = (a[i] / (pts[i]));
            long long l_o = (a[i] % (pts[i]));
            long long k_o = pts[i] - l_o;

            long long diff = k_o*d_o*d_o+l_o*(d_o + 1)*(d_o + 1) - k_n*d_n*d_n-l_n*(d_n + 1)*(d_n + 1);
            q.push({diff, i});

        }
    }

    cout << sum - sumdiff;





}