#include<bits/stdc++.h>
using namespace std;

int main(){
    long n,s;
    cin >> n >> s;
    pair <double, long> r[1005];
    for(int i=0; i<n; i++){
        long a,b,c;
        cin >> a >> b >> c;
        r[i].first = (double) sqrt(a*a + b*b);
        r[i].second = c;
    }
    sort(r,r+n);
    long p = s, i=0;
    while (p < 1000000 && i < n){
        while (r[i] == r[i+1]) {p += r[i].second; i++;}
        p += r[i].second;
        i++;
    }
    if (p < 1000000) {cout << "-1" << endl;}
    else printf("%.7lf\n", r[i-1].first);
    return 0;
}