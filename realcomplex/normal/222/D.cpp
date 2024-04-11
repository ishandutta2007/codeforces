#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

int main(){
    fastIO;
    int n,x;
    cin >> n >> x;
    int a[n],b[n];
    for(int i = 0;i<n;i++)
        cin >> a[i];
    for(int j = 0;j<n;j++)
        cin >> b[j];
    sort(a,a+n);
    sort(b,b+n);
    int p = n-1;
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(a[i]+b[p]>=x)
            p--,cnt++;
    }
    cout << "1 ";
    cout << cnt << "\n";
    return 0;
}