#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100;

int n;

int a[maxn];

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int answer = 0;
    for (int i = 0; i < n; i++)
    if (i > 0 && i < n - 1 && a[i] > a[0] && a[i] < a[n - 1]){
        answer++;
    }
    cout << answer;
}