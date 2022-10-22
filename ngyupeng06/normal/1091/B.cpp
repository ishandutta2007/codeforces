#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

li n;
pll arr[1005], arr1[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i].first >> arr[i].second;
    for (int i=0; i<n; i++) cin >> arr1[i].first >> arr1[i].second;
    sort(arr,arr+n);
    sort(arr1,arr1+n, greater<pll>());
    cout << arr[0].first + arr1[0].first << " " << arr[0].second + arr1[0].second;
}