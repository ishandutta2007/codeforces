#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

//x is 64-bit variable;
LL x;
int d, n;
int a[111111], b[111111], c[111111];


LL getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

const int BASE = 500;
int main() {
    scanf("%d%d%lld", &n, &d, &x);
    initAB();

    if (d <= BASE) {
        vector<int> v;
        for (int i=0; i<n; i++) if (b[i]) v.push_back(i);
        for (int i=0; i<n; i++) {
            for (int j=0; j<(int)v.size() && v[j] <= i; j++)
                c[i] = max(c[i], a[i-v[j]]);
        }
    } else {
        vector<pair<int,int> > v;
        for (int i=0; i<n; i++) if (a[i] >= n-BASE) v.push_back(make_pair(a[i], i));
        sort(v.rbegin(), v.rend());
        
        for (int i=0; i<(int)v.size(); i++) {
            int value = v[i].first, p = v[i].second;
            for (int j=0; j+p<n; j++) {
                if (b[j]) c[p+j] = max(c[p+j], value);
            }
        }
        for (int i=0; i<n; i++) {
            if (c[i] == 0) {
                for (int j=0; j<=i; j++) c[i] = max(c[i], a[j] * b[i-j]); 
            }
        }
    }
    
    for (int i=0; i<n; i++) printf("%d\n", c[i]);
    return 0;
}