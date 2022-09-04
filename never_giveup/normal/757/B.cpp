/*
ID: ramil-p1
PROG: balancing
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100, inf = 1e9 + 100;

int a[maxn];

int main(){
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    #endif
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int answer = 1;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        for (int i = 1; i <= sqrt(x); i++)
        if (x % i == 0){
            if (i != 1)
                a[i]++;
            if (i != sqrt(x))
                a[x / i]++;
        }
    }
    for (int i = 0; i < maxn; i++)
        answer = max(answer, a[i]);
    cout << answer;
}