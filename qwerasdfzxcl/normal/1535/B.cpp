#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[2020];

void solve(){
    int n;
    scanf("%d",  &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    vector<int> v;
    for (int i=0;i<n;i++) if (a[i]&1) v.push_back(a[i]);
    int cnt = 0;
    for (int i=0;i<(int)v.size()-1;i++){
        for (int j=i+1;j<(int)v.size();j++) if (__gcd(v[i], v[j])>1) cnt++;
    }
    printf("%d\n", cnt+(int)v.size()*(n-(int)v.size())+(n-(int)v.size()-1)*(n-(int)v.size())/2);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}