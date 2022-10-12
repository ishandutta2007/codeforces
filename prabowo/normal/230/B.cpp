#include<bits/stdc++.h>
using namespace std;

long n;
bool p[1000001];

int main(){
    memset(p,1,sizeof(p));
    p[1] = false;
    p[0] = false;
    int i,j;
    for(i=2; i<=1000; i++){
        if (p[i]){
            for(j = 2*i; j <= 1000000; j += i) p[j] = false;
        }
    }

    scanf("%ld", &n);
    long long x;
    for(i=0; i<n; i++){
        cin >> x;
        long long t = sqrt(x);
        if (t * t == x && p[(long) sqrt(x)]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}