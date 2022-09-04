#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 100;

int n;

int k;

int d[maxn], sz;

bool is[maxn];

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> n >> k;
    int kk = k;
    for (int i = 2; i <= sqrt(kk); i++)
        if (kk % i == 0){
            d[sz] = 1;
            while (kk % i == 0)
                d[sz] *= i, kk /= i;
            sz++;
        }
    if (kk > 0)
        d[sz] = kk, sz++;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        for (int j = 0; j < sz; j++)
            if (x % d[j] == 0)
                is[j] = 1;
    }
    for (int i = 0; i < sz; i++)
    if (!is[i]){
        cout << "No";
        return 0;
    }
    cout << "Yes";
}