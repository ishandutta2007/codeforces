#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long n, h, prev = 0;
    cin >> n >> h;
    vector<long long> width (n + 1);
    vector<long long> space (n);
    for (int i = 0; i < n; ++i){
        long long x1, x2;
        cin >> x1 >> x2;
        width[i + 1] = x2 - x1;
        space[i] = x1 - prev;
        prev = x2;
    }
    for (int i = 1; i < n; ++i){
        width[i + 1] += width[i];
        space[i] += space[i - 1];
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i){
        long long l = i, r = n;
        while (r - l > 1){
            long long m = (l + r) / 2;
            if (space[m] < space[i] + h)
                l = m;
            else
                r = m;
        }
        long long v;
        if (r < n)
            v = h + width[r] - width[i];
        else
            v = h + width[n] - width[i];
        if (v > ans)
            ans = v;
    }
    cout << ans;
}