#include<bits/stdc++.h>
using namespace std;

int main(){
    long n,d;
    long a,b;
    cin >> n >> d;
    cin >> a >> b;
    pair <long, long> m[100002];
    for(long i=0; i<n; i++){
        long x,y;
        cin >> x >> y;
        m[i].first = x * a + y * b;
        m[i].second = i+1;
    }
    sort(m,m+n);
    long i = 0, ans[100001];
    while (d >= m[i].first && i < n){
        d -= m[i].first;
        ans[i] = m[i].second;
        i++;
    }
    cout << i << endl;
    for (long j=0; j<i; j++){
        if (j > 0) cout << " ";
        cout << ans[j];
    }
    cout << endl;

    return 0;
}