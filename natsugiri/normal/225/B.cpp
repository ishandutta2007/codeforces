#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


typedef long long LL;

int s, k;
int main() {
    scanf("%d%d", &s, &k);
    vector<int>v;
    v.push_back(0);
    if (k>=30) {
        for (int i=0; (1<<i)<=s; i++) {
            if (s&(1<<i)) v.push_back(1<<i);
        }
    } else {
        int x=1;
        vector<int>f;
        for (int i=1; i<k; i++) f.push_back(0);
        f.push_back(1);
        for (int i=0; x<=s; i++) {
            f.push_back(x);
            x=x*2-f[i];
        }

        int n=f.size();
        for (int i=n-1; s && i>=0; i--) {
            if (s>=f[i]) {
                s-=f[i];
                v.push_back(f[i]);
            }
        }
    }
    int n=v.size();
    printf("%d\n", n);
    for (int i=0; i<n; i++) printf("%d%c", v[i], i==n-1?'\n':' ');

    return 0;
}