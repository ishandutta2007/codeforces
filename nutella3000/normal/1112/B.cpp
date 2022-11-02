#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int roun(double a) {
    return (a + 0.5);
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin.precision(10);
    cout.precision(10);
    int n,k;
    int ans = 0;
    cin >> n >> k;
    int a[n];
    vector<int> end;
    vector<int> begin;
    vector<int> for_an;
    vector<int> round_time;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    for(int i = 0;i < min(n,k);i++) {
        end.push_back(a[i]);
        begin.push_back(0);
        for_an.push_back(i);
    }
    int id = k;
    int m = 0;
    bool an[n];
    for(int i = 0;i < n;i++) an[i] = false;
    for(int i = 1;i < n * 150;i++) {
        int round_time = roun((double)m / n * 100);
        for(int j = 0;j < begin.size();j++) {
            if (i - begin[j] == round_time) an[for_an[j]] = true;
        }
        while(true) {
            bool u = false;
            for(int j = 0;j < end.size();j++) {
                if (end[j] == i) {
                    m++;
                    end.erase(end.begin() + j);
                    begin.erase(begin.begin() + j);
                    for_an.erase(for_an.begin() + j);
                    if (id < n) {
                        end.push_back(i + a[id]);
                        begin.push_back(i);
                        for_an.push_back(id);
                        id++;
                    }
                    u = true;
                    break;
                }
            }
            if (!u) break;
        }
    }
    for(int i = 0;i < n;i++) ans += an[i];
    cout << ans;
}