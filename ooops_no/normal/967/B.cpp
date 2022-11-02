#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    vector <int> v(a - 1);
    ll sum = 0;
    int n;
    cin >> n;
    sum = sum + n;
    for (int i = 0; i < a - 1; i++){
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    int l = a - 2;
    while (n * b / sum < c){
        sum -= v[l];
        l--;
        cnt++;
    }
    cout << cnt;
}