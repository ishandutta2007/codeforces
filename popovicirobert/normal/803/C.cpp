#include <bits/stdc++.h>


using namespace std;

vector <long long> sol;

long long n, k, rad;
bool flag = 1;

inline void check(long long d) {
    if(k >= 150000)
        return ;
    if(n / d < k * (k + 1) / 2)
        return ;
    sol.clear();
    for(int i = 1; i <= k; i++) {
        sol.push_back(i * d);
        n -= i * d;
    }
    flag = 0;
    sol[sol.size() - 1] += n;
}

int main() {
  //  fstream cin("A.in");
  //  ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    long long d = 1;
    while(d * d <= n && flag) {
        if(n % d == 0)
            check(n / d);
        d++;
    }
    d = sqrt(n);
    while(d >= 1 && flag) {
        if(n % d == 0)
            check(d);
        d--;
    }
    if(flag == 0) {
        for(auto it : sol)
            cout << it << " ";
    }
    else
        cout << -1;
   // cin.close();
   // cout.close();
    return 0;
}